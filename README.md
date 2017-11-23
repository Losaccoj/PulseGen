# PulseGen
Teensy-driven pulse generator for TTL pulse trains (e.g. for optogenetic experiments)
<img src="https://github.com/Losaccoj/PulseGen/blob/master/PulseGen_face.jpg" width="476" height="430"> 
<img src="https://github.com/Losaccoj/PulseGen/blob/master/PulseGen_connections.jpg" width="426" height="175">

## Pulse Timing
![Alt text](PulseGen_desc.jpg?raw=true)


### Usage
1. Upon boot (after splash screen (splash)), user must input stimulus parameters (user_params) on keypad following prompts. 
   - #: Enter  
   - A: Accept   
   - C: Clear 
  
2. Once stimulus parameters are established, PulseGen waits for an input before sending triggers out (stim_gen) according to the stimulus parameters. These triggers can either be:
   - Manual button-press (trig2)
   - TTL input (trig1)

   In either input case, stimulus triggers are sent out over TTL1 and LED1 simultaneously according to the stimulus parameters. 
