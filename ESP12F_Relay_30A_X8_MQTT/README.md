Usage:


        mosquitto_pub -d -t arduino/simple -m "switch:X:Y"
    
where:

        X = relay number 1 ÷ 8
        Y = relay state:
                          0 - OFF
                          1 - ON

TODO:

        publish led status
               add new topic
               put led status in string array and publish on new topic
