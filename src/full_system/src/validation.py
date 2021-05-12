#!/usr/bin/env python3

# General libs
import os
import time
import pandas as pd
from threading import Condition

# ROS libs
import rospy
from interfaces.msg import trace_events
from system_msgs.msg import abstractions

MANEUVERS_START = {
    'st_app' : 'approach',
    'st_exp' : 'exploration',
    'st_vsv' : 'surroundings verification',
    'st_rb' : 'return to base',
    'st_tele' : 'teleoperation',
    'uav_st_app' : 'approach',
    'uav_st_assess' : 'assessment',
    'uav_st_v_search' : 'victim search',
    'uav_st_vsv' : 'surroundings verification',
    'uav_st_rb' : 'return to base',
    'uav_st_tele' : 'teleoperation',
    'uav_st_safe_land' : 'safe land'
}

MANEUVERS_STOP = ['end_app', 'end_exp', 'end_vsv', 'end_rb', 'end_tele',
                  'er_app', 'er_exp', 'er_vsv', 'er_rb', 'er_tele',
                  'sus_app', 'sus_exp', 'sus_vsv', 'sus_rb',
                  'uav_end_app', 'uav_end_assess', 'uav_end_v_search', 'uav_end_vsv', 'uav_end_rb', 'uav_end_tele', 'uav_end_safe_land',
                  'uav_er_app', 'uav_er_assess', 'uav_er_v_search', 'uav_er_vsv', 'uav_er_rb', 'uav_er_tele', 'uav_er_safe_land',
                  'uav_sus_app', 'uav_sus_assess', 'uav_sus_v_search', 'uav_sus_vsv', 'uav_sus_rb']


class Validation(object):

    def __init__(self, robots_names, period, filename):
        self.robots = robots_names
        self.samples_period = period 
        self.filename = filename

        self.new_sample_flag = Condition()

        # Defines collumns names related to desired informations
        cols = ['allocated_robots', 'available_robots', 'teleoperations']
        for r in self.robots:
            cols.append(r + '_cur_maneuver')
            cols.append(r + '_tasks_counter')

        self.samples = pd.DataFrame(columns = cols)

        # Initialize variables
        self.allocated_n = 0 
        self.available_n = len(self.robots)
        self.tele_count = 0

        self.r_cur_task = {}
        self.robots_status = {}
        self.robots_counter = {}
        self.allocated_robots = {}
        for r in self.robots:
            self.r_cur_task[r] = 'None'
            self.robots_status[r] = 'ok'
            self.robots_counter[r] = 0
            self.allocated_robots[r] = False


        # Subscribe to topics
        for r in self.robots:            
            rospy.Subscriber("/{}/events_abstractions".format(r), abstractions, self.abs_cbk, r)
        
        rospy.Subscriber("/events_trigger_ihm_in", trace_events, self.trace_cbk)


    def abs_cbk(self, msg, robot):
        '''
            Monitor:
                -available robots;
                -robot finished tasks counter;
                -allocated robots
        '''
        # print("\n\nAbstraction msg from {}:".format(robot))
        # print(msg)

        self.new_sample_flag.acquire()

        if msg.event == 'robot_unable':
            self.robots_status[robot] = 'nok'
        elif msg.event in ['robot_idle','robot_busy']:
            self.robots_status[robot] = 'ok'
        elif 'task_finished' in msg.event:
            self.robots_counter[robot] += 1
            self.allocated_robots[robot] = False
        elif 'task_aborted' in msg.event:
            self.allocated_robots[robot] = False
        elif 'task_executing' in msg.event:
            self.allocated_robots[robot] = True
        else:
            self.new_sample_flag.release()
            return

        self.new_sample_flag.notify()

        self.allocated_n = sum(list(self.allocated_robots.values()))
        self.available_n = sum(v == 'ok' for v in list(self.robots_status.values()))

        self.new_sample_flag.notify()
        self.new_sample_flag.release()

    def trace_cbk(self, msg):
        '''
            Monitor:
                -teleoperation occurances;
                -robots current maneuver
        '''
        # print("\n\nTrace msg:")
        # print(msg)

        self.new_sample_flag.acquire()

        if 'st_tele' in msg.last_event:
            self.tele_count += 1

        if msg.last_event in MANEUVERS_START:
            self.r_cur_task[msg.robot] = MANEUVERS_START[msg.last_event]
            self.new_sample_flag.notify()
        elif msg.last_event in MANEUVERS_STOP:
            self.r_cur_task[msg.robot] = 'None'
            self.new_sample_flag.notify()

        self.new_sample_flag.release()


    def run(self):
        while not rospy.is_shutdown():
            self.new_sample_flag.acquire()
            self.new_sample_flag.wait(self.samples_period)
            
            # Update samples
            sample = [self.allocated_n, self.available_n, self.tele_count]
            for r in self.robots:
                sample.append(self.r_cur_task[r])                       # robot current task
                sample.append(self.robots_counter[r])                   # robot tasks counter
            self.samples.loc[time.strftime("%H:%M:%S")] = sample

            # print(self.samples)
            self.samples.to_csv(self.filename)
            self.new_sample_flag.release()


    ###############################################################################################

if __name__ == '__main__':
    try:
        #Change to the current directory
        path = os.path.dirname(os.path.abspath(__file__))
        os.chdir(path)

        samples_filename = path + '/samples/{}.csv'.format(time.strftime("%b-%d-%Y  %H:%M:%S"))

        robots = rospy.get_param("robots", default = ['pioneer3at_1', 'pioneer3at_2','UAV_1','UAV_2'])
        samples_period = rospy.get_param("sample_period", default = 10)

        rospy.init_node('system_monitor', anonymous=False)      # Initialize the node of the validation monitor
        monitor = Validation(robots, samples_period, samples_filename)
        monitor.run()                                           # Start main loop
        
        rospy.spin()
            
    except rospy.ROSInterruptException:
        pass
