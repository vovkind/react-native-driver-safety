#ifndef FINDEVENT_H
#define FINDEVENT_H

#include <vector>

#include <stdint.h>
#include <string>
#include <vector>
#include "Tools/vec32.hpp"

#include "statistical.hpp"


enum class EventName:int
{
  NOT_DEFINED=0,
  PHONE_USING,
  CORNERING,
  ACCELERATION,
  BRAKING,
  DISTORTION
};

class coordinate{
public:
      double latitude;
      double longitude;
      coordinate(){};
      coordinate(double latitude_ ,double longitude_){
        latitude = latitude_;
        longitude = longitude_;
      }

};

class DataPoint{
public:
    double time;
    double speed;
    double accuracy;
    coordinate geopoint;
    Vec32  acceleration;
    Vec32  gyroscope;
    void clear(){
        time = 0.0f;
        speed = 0.0f;
        accuracy = 0.0f;
        acceleration.Clear();
        gyroscope.Clear();
        geopoint = coordinate();
    }
    DataPoint(){
        clear();
    }
    ~DataPoint(){
        clear();
    }
};


class EventPoint{
    public:
    //Поля продолжительности
    double duration;
    double pure_duration;
    double prev_start_speed;
    
    DataPoint start,stop;
    
    EventName name;
    StatisticalValue speed,x,y,z,accuracy;
    void clear(){
        start.clear();
        stop.clear();
        duration = 0.0;
        pure_duration = 0.0;
        speed = StatisticalValue();
        x = StatisticalValue();
        y = StatisticalValue();
        z = StatisticalValue();
        accuracy = StatisticalValue();
        name = EventName::NOT_DEFINED;
        return;
    }

    EventPoint(){
        clear();
    };
    ~EventPoint(){
        clear();
    };
};

class EventData{
  public:
  std::vector <EventPoint> vector_;
  StatisticalData speed,x,y,z,accuracy;
  EventName name_;
  EventPoint point_;
  bool state_ ;
  bool seach_state_;
  double last_state_time_;
  void clear(void){
    vector_.clear();
    name_= EventName::NOT_DEFINED;
    point_.clear();
    state_ = false;
    seach_state_ = false;
    last_state_time_ = 0.0;
    speed.Clear();
    x.Clear();
    y.Clear();
    z.Clear();
    accuracy.Clear();
  }
  EventData(){
      clear();
  }
  EventData(EventName name){
      clear();
      name_ = name;
  }
  ~EventData(){
      clear();
  }
    
};

bool FindEventOptimized(EventData *event, DataPoint &current_point, bool event_triger);
size_t CheakEvent(EventData *event);
EventData GetEvents(EventData *event, bool clear_out);
double GetPrevSpeed(double speed);

#endif // FINDEVENT_H
