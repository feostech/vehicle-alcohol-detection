# MOSQUITTO MQTT SETUP: 

## Installation mosquitto in terminal:

https://mosquitto.org/download/ 

```
sudo apt-add-repository ppa:mosquitto-dev/mosquitto-ppa  

sudo apt-get install mosquitto 

sudo apt-get install mosquitto-clients
```
 
## Configuration methods: 

 

https://mosquitto.org/documentation/authentication-methods/  

https://test.mosquitto.org/config/

The above sites has the config method to make the connection successfully. 


### My mosquitto.conf file: 

```
 #Place your local configuration in /etc/mosquitto/conf.d/ 
 
 
 #A full description of the configuration file is at 

 #/usr/share/doc/mosquitto/examples/mosquitto.conf.example 

 persistence true 

 persistence_location /var/lib/mosquitto/ 

 log_dest file /var/log/mosquitto/mosquitto.log 

 include_dir /etc/mosquitto/conf.d  

 listener 1883          
 allow_anonymous true
```
 

## After configuring the file:

```
sudo mosquitto -c /etc/mosquitto/mosquitto.conf  
```
Which is used to connected with the remote server (Mobile)

we need to give the mosquitto -c config with its < path > to make connection. 

In another terminal we need to get subscribe with our topic by using, 

```
mosquitto_sub -v -t "Topic_name"
```

 It shows the value that our client sends by using the mobile. 

https://stackoverflow.com/questions/26716279/how-to-test-the-mosquitto-server (Ref. for Testing the server which we get to connect now.) 

open 3 terminal windows and each window should run these 3 different commands.
```
1:  sudo mosquitto -c /etc/mosquitto/mosquitto.conf

2:  mosquitto_sub -v -t "Topic_name" 

3:  sudo tail -f /var/log/mosquitto/mosquitto.log 
```
 

### Checking the log whether the client is connected or not: 
```
sudo tail -f /var/log/mosquitto/mosquitto.log 
```
To check the client connectivity.

 

# Installing the MQTT Client in Mobile:  

https://play.google.com/store/apps/details?id=com.doikov.mqttclient  

Install MQTT client App in your mobile and set the broker with the Name, URL (IP address) and give done. It Automatically connected. 

After we connected the mobile with the url to send message through the mobile. The message received in the terminal where we used to set that topic name. 

 

 
