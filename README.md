# xbee_pro_interface_arduino
Repository that has Arduino code to interface with the XBee SX Pro radio module. Designed to be an Arduino library.
The module commnicates via a UART port on the Arduino. The code helps with sending AT commands that switch the device into command mode and also change AT registers on the device. It also will contain functions that send data to the radio module to be transmitted to the base station. The actual protocol code will be contained in a seperate repository.

## Usage
To install the library in Arduino IDE, follow the instructions below:
- Click the "Clone or Download" button and click "Download ZIP"
- Click on the ZIP file after it finishes downloading and extrac the folder to your Arduino sketchbook directory. By default this is Documents/Arduino/libraries
- Alternatively, open the Arduino IDE and navigate to Sketch -> Include Library -> Include .ZIP Library and restart Arduino IDE
- That's it! Now in Arduino IDE go to File -> Examples -> SXPro -> Examples to load the example sketch
