#  author rescuer_Liao
#  description :
#  this is for team xm's cute face and
#  this is only static pictrue in Qt
#  this node is designed to send socket to change the pictrue in Qt

#!/usr/bin/env python
#encoding:utf8

import rospy
import roslib
import socket
import math
from xm_face_msgs.msg import *
from numpy import *
FACE_HOST = '127.0.0.1'
FACE_PORT = 8001

class xm_face_node(object):
    def __init__(self):
        self.__face_qt_socket = socket.socket(socket.AF_INET , socket.SOCK_STREAM)
        self.get_socket_init()
        self.__xm_face_sub = rospy.Subscriber('/team_xm/face',xm_face,self.xm_face_callback)

    def get_socket_init(self):
        global  FACE_PORT,FACE_HOST
        self.__face_qt_socket.connect((FACE_HOST,FACE_PORT))
        rospy.loginfo('xm_face init successfully!')

    def send_xm_face_order(self,face_id):
        #rospy.loginfo(data)
        self.__face_qt_socket.send(str(face_id))
        rospy.loginfo('change the xm_face')

    def xm_face_callback(self,msg):
        self.send_xm_face_order(msg.xm_face_type)

if __name__=='__main__':
    rospy.init_node('xm_face')
    xm_face = xm_face_node()
    xm_face.send_xm_face_order(1)
    rospy.spin()


