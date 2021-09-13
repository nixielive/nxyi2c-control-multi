# **NXYI2C Multiple tube control sample**

This sketch displays some patterns with `I2C nixie tube control module (= NXYI2C)`.

For more information about NXYI2C, please visit [here](https://www.nixielive.com).

This sketch requires 5 NXYI2Cs with I2C addresses 21 to 25 written on it.
See the following for how to write NXYI2C and I2C addresses.

* [I2C nixietube control module (NXYI2C)](https://www.nixielive.com/docs/nxyi2c_module)
* [How to upload your sketch to NXYI2C](https://www.nixielive.com/docs/nxyi2c_upload)
* [Default firmware sketch of NXYI2C](https://github.com/nixielive/nxyi2c-default-firmware)

# **Sketch Description**
This sketch should be written to the Arduino, which is the master of I2C. The following pattern will be displayed on the nixie tubes connected to the Arduino via I2C.

|I2C addr|ID|description|
|:---|:---|:---|
|21|2|Simply lights up.|
|22|3|The light will gradually brighten.|
|23|4|It will gradually get darker.|
|24|5|The previous number gets progressively darker and the next number gets progressively lighter. |
|25|7|The next number will gradually get brighter, and the numbers other than that will gradually get darker. |

## **How to send command to a NXYI2C**

For more information about sending commands, please reffer [NXYI2C Single tube control sample](https://github.com/nixielive/nxyi2c-control-single).

