# Reflection for PID Controller Project

## Effect of each of the P, I, D components 

**Proportional (P):** The proportional component of a PID algorithm applies a correction directly proportional and inverse to the deviation from the middle of the road.

In our simulation, this component exerts the lateral force to the car needed to bend the curves and follow the road. 

If the P component is too low, no enough correction will be applied when the car goes off the middle, and especially on curves it can run off track.

If the P component is too high, the car will overcorrect the deviation, moving to the other side of the road and again overcorrect back. This causes an oscillation of the car around the middle of the road. This leads to a dangerous driving that can make the car to swerve off the road at worst, and would be quite uncomfortable at best.

Ultimately no single value can make the car turn tight corners without causing oscillations on straight driving. This effect has to be compensated with the D component.

**Derivative (D):** The derivative component of a PID algorithm compensates the P component by applying a correction proportional to the derivative of the deviation of the car. Thus, when the deviation gets smaller (the car is already correcting to the center) the D component is opposite to the P, atenuating the overcorrection.

If D is to low, we will still have the car oscillation, specially on straight parts of the road.

If D is too high there is an overreaction to any increase or decrease of the distance to the middle, and the car will change course more abruptly, eventually wriggling around the center line and slowing down the driving.

**Integral (I):** The integral part of a PID algorithm applies a correction proportional to the sum, or area, of the total deviation of the road along the drive. If the steering of the car is perfectly aligned the P and the components will make the deviations to the right equal to the deviations to the left, and the I component will equal zero. However, if the steering is misaligned the car will stay longer on one side of the center, and the I component will compensate this error along the drive.

As the car in our simulation seems to have a well calibrated steering mechanism, a low or null value of I did not have a big effect in the car's behavior.

A high value of I will make the car oscillate and swerve more, specially at the beginning when the two sides of the deviation do not cancel each other well. 

## Choosing the final hyperparameters

I tried to use the Twiddle algorithm to more systematically choose the PID hyperparameters, using a loss function proportional to the squared deviation (Cross Track Error or CTE), and the mean velocity. However, as the simulation has to be run manually, this proved to be not the right approach for me.

Finally the method result was to manually set small increases of the parameters and observe the driving results on our vehicle. Beginning with the P-parameter, small and careful increases will eventually make the car turn the first curve. Then it can be clearly observed an oscillation on the straight path over the bridge. This oscillation gave a great feedback to start increasing the D-parameter until the oscillation disappears. 

After that, following curves are tighter than the first one, and the P- and D-parameters have to be increased again in the same careful fashion until the car overcomes each curve. 

Increasing carefully is very important, because a too high value of P can be compensated with a higher value of D. These two values can the be pushed upwards a long way and the car will manage to do the circuit, but the driving will be very abrupt on every deviation, making the ride very uncomfortable and slow.

A very small value of I-parameter showed a decreased on the mean CTE-squared around a loop, and marginally seemed to improve the driving, but any increase quickly worsened it. This shows that the simulation has zero or almost zero steering deviation included.

## PID for Throttle

I decided to create another pid object for speed (named spid :) to control the throttle, that was set as constant in the starter code. This second PID was much easier to set up and a low value of P and D already provides for a good acceleration and braking. The PID reacts to compensate a deviation from a goal velocity. I set this goal velocity proportional to the speed limit and inverse to the steering angle. This way I emulate the standard driving rule of driving slower on curves, and create an additional compensation in driving behavior.

The speed limit can be set up higher. With these hyperparameters the car is able to complete a loop at up to 75 MPH. However the oscillations gets bigger and more difficult to control even with increased D-parameter, so I keep the project delivery with the standard 30 MPH speed limit.
