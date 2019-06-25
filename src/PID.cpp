#include "PID.h"


/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  p_error = 0;
  i_error = 0;
  d_error = 0;
  first = true;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  if(first) {
    prev_cte = cte;
    first = false;
  }
  d_error = cte - prev_cte;
  p_error = cte;
  i_error += cte;

  prev_cte = cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return (-Kp * p_error - Ki * i_error -  Kd * d_error);  // TODO: Add your total error calc here!
}

double PID::Correction() {
  cout << "P: " << -Kp * p_error << endl;
  cout << "I: " << -Ki * i_error << endl;
  cout << "D: " << -Kd * d_error << endl;
  return (-Kp * p_error - Ki * i_error -  Kd * d_error);
}


//void PID::Twiddle(int param, vector<double> p, vector<double> dp,
//                  double total_error, double best_err, vector<bool> repeat){
//
////  double error = TotalError();
////  double mean_speed = MeanSpeed();
////  double total_error = error * (30-mean_speed);
//  if(total_error < best_err){
//    dp[param] *= 1.1;
//    p[param] += dp[param];
//    repeat[param] = true;
//    cout << "Next p: {"<< p[0]<<", "<<p[1]<<", "<<p[2]<<"}"<< endl;
//    cout << "Next dp: {"<< dp[0]<<", "<<dp[1]<<", "<<dp[2]<<"}"<< endl;
//    cout << "Next Repeat: {" << repeat[0]<<", "<<repeat[1]<<", "<<repeat[2]<<"}"<< endl;
//    cout << "Next best error: " << total_error << " !!!" << endl;
//
//  }
//  else {
//    if(repeat[param]){
//      p[param] -= 2*dp[param];
//      repeat[param] = false;
//      cout << "Next p: {"<< p[0]<<", "<<p[1]<<", "<<p[2]<<"}"<< endl;
//      cout << "Next dp: {"<< dp[0]<<", "<<dp[1]<<", "<<dp[2]<<"}"<< endl;
//      cout << "Next Repeat: {" << repeat[0]<<", "<<repeat[1]<<", "<<repeat[2]<<"}"<< endl;
//      cout << "Next best error: " << best_err << " /" << endl;
//
//    }
//    else{
//      p[param] += dp[param];
//      dp[param] *= 0.7;
//      p[param] += dp[param];
//      repeat[param] = true;
//      cout << "Next p: {"<< p[0]<<", "<<p[1]<<", "<<p[2]<<"}"<< endl;
//      cout << "Next dp: {"<< dp[0]<<", "<<dp[1]<<", "<<dp[2]<<"}"<< endl;
//      cout << "Next Repeat: {" << repeat[0]<<", "<<repeat[1]<<", "<<repeat[2]<<"}"<< endl;
//      cout << "Next best error: " << best_err << " /" << endl;
//
//    }
//  }
//}
