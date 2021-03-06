# PulseGen
Teensy-driven pulse generator for TTL pulse trains (e.g. for optogenetic experiments).
The enclosure STL files are in the folder entitled 'Enclosure'. There is also a bill of materials and rough wiring guide. 

<img src="https://github.com/Losaccoj/PulseGen/blob/master/jpg/front.jpg" width="426" height="422"> <img src="https://github.com/Losaccoj/PulseGen/blob/master/jpg/top.jpg" width="426" height="223"> <img src="https://github.com/Losaccoj/PulseGen/blob/master/jpg/wiring layout.PNG" width="559" height="546">

## Pulse Timing
<img src="https://github.com/Losaccoj/PulseGen/blob/master/jpg/PulseGen_desc.jpg" width="650" height="244">

> - Trigger: External 5V TTL input to initiate stimulation OR button-press on PulseGen
> - Delay: Time delay between trigger and stimulus. Set to 0 for immediate stimuluation with trigger
> - Dur: Duration/pulse width
> - IPI: Inter-pulse interval
> - \# of Pulses: Number of pulses in "pulse train". Set to 1 for one pulse


### Usage
1. Upon boot (after splash screen (splash)), user must input stimulus parameters (user_params) on keypad following prompts. 
   - #: Enter     
   - *: Clear 
  
2. Once stimulus parameters are established, PulseGen waits for an input before sending triggers out (stim_gen) according to the stimulus parameters. These triggers can either be:
   - Manual button-press (trig2)
   - TTL input (trig1)

   In either input case, stimulus triggers are sent out over TTL1 (e.g. BNC cable) and LED1 (on face of device) simultaneously according to the stimulus parameters. 

#### Acknowledgments
My initial source of inspiration came from Andrew Scallon at the Optogenetics and Neural Engineering <a href="https://optogeneticsandneuralengineeringcore.github.io/ONECoreSite/">(ONE) Core</a> at the University of Colorado, Anschutz Medical Center. 

I would also like to thank the folks behind <a href="https://sanworks.io/shop/viewproduct?productID=1102">Pulse Pal</a> (Joshua Sanders (the founder) as well as contributers Josh Siegle and Goncalo Lopes) for inspiration as to the feasibility of the project as well as the idea for the opto-isolation (TLP2530) protection of the Teensy. 

The characterization of the Pulse Pal's performance in this paper by <a href="https://www.ncbi.nlm.nih.gov/pmc/articles/PMC4263096/">Sanders and Kepecs 2014</a> is admirable and I intend to do the same with PulseGen as well. 

