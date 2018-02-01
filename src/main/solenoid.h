#ifndef _SOLENOID_H
#define _SOLENOID_H

#ifdef __cplusplus
extern "C" {
#endif

#define SOLENOID1 2
#define SOLENOID2 3

void solenoid_init(int solenoidPin);
void solenoid_open(int solenoidPin);
void solenoid_close(int solenoidPin);


#ifdef __cplusplus
}
#endif

#endif
