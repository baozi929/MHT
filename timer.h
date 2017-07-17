#pragma once
#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <time.h>
#define TIMER_ON

// 改用这个，和手机计时差不多
static const double clock_tics_per_sec = CLOCKS_PER_SEC;//1000000.0;
class Timer {
   clock_t last_time;
   clock_t cur_time;
   double  time_dur;

 public:

   void reset_clock() {
     last_time = cur_time = clock();
   }

   Timer() { time_dur=0.0; reset_clock();}

   void report_cumm_time(char* s) {              // 计算累计时间，print
#ifdef TIMER_ON
     cur_time = clock();
     double tmp = (cur_time-last_time)/clock_tics_per_sec;
     time_dur += tmp;
     printf("%s: %f secs\n",s, time_dur);
#endif
    }

   void report_time(char* s) {                  // 重新计时，print delta(t)
#ifdef TIMER_ON
     cur_time = clock();
     double tmp = (cur_time-last_time)/clock_tics_per_sec;
     if (tmp > 0.0) {
        printf("%s: %f secs\n",s, tmp);
      }
     last_time = cur_time;
#endif
    }

    double elapsedTime( void )                 // 重新计时，返回delta(t)
    {
      cur_time = clock();
      double tmp = (cur_time - last_time) / clock_tics_per_sec;
      last_time = cur_time;
      return tmp;
    }
 };

#endif
