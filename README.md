# PulseGen
Teensy-driven pulse generator for TTL pulse trains (e.g. for optogenetic experiments)

## Pulse Timing
<blockquote class="imgur-embed-pub" lang="en" data-id="a/N2U4C"><a href="//imgur.com/N2U4C"></a></blockquote><script async src="//s.imgur.com/min/embed.js" charset="utf-8"></script>


### Usage
1. Upon boot (after splash screen (splash)), user must input stimulus parameters (user_params) on keypad following prompts. 
   - #: Enter  
   - A: Accept   
   - C: Clear 
  
2. Once stimulus parameters are established, PulseGen waits for an input before sending triggers out (stim_gen) according to the stimulus parameters. These triggers can either be:
   - Manual button-press (trig2)
   - TTL input (trig1)

   In either input case, stimulus triggers are sent out over TTL1 and LED1 simultaneously according to the stimulus parameters. 
