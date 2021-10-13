FROM centos
COPY dsn-5.cpp  . 
RUN yum install vim -y
RUN yum install gcc-c++ -y