#ifndef MSG_H
#define MSG_H

#include "Date.h"
#include "Time.h"
#include <string>

/* Class: Msg
 * Purpose: Represents a single text message metadata record in the telco
 * system, storing source and destination phone numbers along with dynamically
 *          allocated Date and Time objects.
 * Members:
 *   - src: string representing the phone number of the sender
 *   - dest: string representing the phone number of the receiver
 *   - date: pointer to the dynamically allocated Date object when the message
 * was sent
 *   - time: pointer to the dynamically allocated Time object when the message
 * was sent
 */

class Msg {
public:
  Msg(int day, int month, int year, int hours, int mins, string src,
      string dest);
  ~Msg();
  bool greaterThan(Msg *msg);
  void print();

private:
  string src;
  string dest;
  Date *date;
  Time *time;
};

#endif
