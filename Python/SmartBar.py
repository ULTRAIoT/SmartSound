__autor__="Michael Kirsch"
import random
import logging
import serial
import  time
logging.getLogger().setLevel(logging.INFO)
import att_iot_client.ATT_IOT as IOT
global s
s = None
s = serial.Serial("/dev/ttyS0", 9600, timeout=2)
IOT.DeviceId = "c3Sup5D8N5bCVCS4pdMPzO5D"
IOT.ClientId = "PaprikaYT_gcHaggvf"
IOT.ClientKey = "G0sFl3FM"
IOT.connect(httpServer='api.allthingstalk.io', secure=False)
IOT.connect()
IOT.addAsset(nosensor, "No2Sensor", "No2Sensor", False, "number")
IOT.addAsset(humSensor, "humSensor", "humSensor", False, "number")
IOT.addAsset(tempSense, "tempSensor", "tempSensor", False, "number")
IOT.addAsset(soundSense, "soundSensor", "soundSensor", False, "number")
IOT.addAsset(fail,"Failures", "Failures", False, "string")
IOT.subscribe()

def getint(asssetid):
    IOT.connect(httpServer='api.allthingstalk.io', secure=False)
    x = IOT.getAssetState(asssetid, device=None)
    x = str(x)
    a, b = x.split(",")
    b = b.replace("}", "")
    b=b.replace("u'value':", "")
    b=int(b)
    return b

def getfloat(asssetid):
    IOT.connect(httpServer='api.allthingstalk.io', secure=False)
    x = IOT.getAssetState(asssetid, device=None)
    x = str(x)
    a, b = x.split(",")
    b = b.replace("}", "")
    b=b.replace("u'value':", "")
    b=float(b)
    return b

def getstring(asssetid):
    x = IOT.getAssetState(asssetid, device=None)
    x = str(x)
    a, b = x.split(",")
    b = b.replace("}", "")
    b=b.replace("u'value':", "")
    return b

while True:
    level=getint(0)
    s.write(str(level)+"$")
    time.sleep(2)