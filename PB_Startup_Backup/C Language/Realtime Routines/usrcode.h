#ifdef __KERNEL__
#include <linux/module.h>
#else
global EXPORT_SYMBOL(x) // x
global KERN_ALERT
global printk printf
#include <gplib.h>
#endif
#include <RtGpShm.h>	// Global Rt/Gp Externals and structures
#include <rtpmacapi.h>

int rtsprintf(char * buf, const char *fmt, ...);

double user_pid_ctrl( struct MotorData *Mptr);
EXPORT_SYMBOL(user_pid_ctrl);

void user_phase( struct MotorData *Mptr);
EXPORT_SYMBOL(user_phase);

void CaptCompISR(void);
EXPORT_SYMBOL(CaptCompISR);

double CfromScript(double arg1,double arg2,double arg3,double arg4,double arg5,double arg6,double arg7,struct LocalData *Ldata);
EXPORT_SYMBOL(CfromScript);

//----------------------------------------
// Required Kinematic define Names
//----------------------------------------
global KinPosMotor  L
global KinVelMotor  R
global KinEnaAxisA 0x1
global KinPosAxisA C[0]
global KinVelAxisA C[32]
global KinEnaAxisB 0x2
global KinPosAxisB C[1]
global KinVelAxisB C[33]
global KinEnaAxisC 0x4
global KinPosAxisC C[2]
global KinVelAxisC C[34]
global KinEnaAxisU 0x8
global KinPosAxisU C[3]
global KinVelAxisU C[35]
global KinEnaAxisV 0x10
global KinPosAxisV C[4]
global KinVelAxisV C[36]
global KinEnaAxisW 0x20
global KinPosAxisW C[5]
global KinVelAxisW C[37]
global KinEnaAxisX 0x40
global KinPosAxisX C[6]
global KinVelAxisX C[38]
global KinEnaAxisY 0x80
global KinPosAxisY C[7]
global KinVelAxisY C[39]
global KinEnaAxisZ 0x100
global KinPosAxisZ C[8]
global KinVelAxisZ C[40]
global KinEnaAxisAA 0x200
global KinPosAxisAA C[9]
global KinVelAxisAA C[41]
global KinEnaAxisBB 0x400
global KinPosAxisBB C[10]
global KinVelAxisBB C[42]
global KinEnaAxisCC 0x800
global KinPosAxisCC C[11]
global KinVelAxisCC C[43]
global KinEnaAxisDD 0x1000
global KinPosAxisDD C[12]
global KinVelAxisDD C[44]
global KinEnaAxisEE 0x2000
global KinPosAxisEE C[13]
global KinVelAxisEE C[45]
global KinEnaAxisFF 0x4000
global KinPosAxisFF C[14]
global KinVelAxisFF C[46]
global KinEnaAxisGG 0x8000
global KinPosAxisGG C[15]
global KinVelAxisGG C[47]
global KinEnaAxisHH 0x10000
global KinPosAxisHH C[16]
global KinVelAxisHH C[48]
global KinEnaAxisLL 0x20000
global KinPosAxisLL C[17]
global KinVelAxisLL C[49]
global KinEnaAxisMM 0x40000
global KinPosAxisMM C[18]
global KinVelAxisMM C[50]
global KinEnaAxisNN 0x80000
global KinPosAxisNN C[19]
global KinVelAxisNN C[51]
global KinEnaAxisOO 0x100000
global KinPosAxisOO C[20]
global KinVelAxisOO C[52]
global KinEnaAxisPP 0x200000
global KinPosAxisPP C[21]
global KinVelAxisPP C[53]
global KinEnaAxisQQ 0x400000
global KinPosAxisQQ C[22]
global KinVelAxisQQ C[54]
global KinEnaAxisRR 0x800000
global KinPosAxisRR C[23]
global KinVelAxisRR C[55]
global KinEnaAxisSS 0x1000000
global KinPosAxisSS C[24]
global KinVelAxisSS C[56]
global KinEnaAxisTT 0x2000000
global KinPosAxisTT C[25]
global KinVelAxisTT C[57]
global KinEnaAxisUU 0x4000000
global KinPosAxisUU C[26]
global KinVelAxisUU C[58]
global KinEnaAxisVV 0x8000000
global KinPosAxisVV C[27]
global KinVelAxisVV C[59]
global KinEnaAxisWW 0x10000000
global KinPosAxisWW C[28]
global KinVelAxisWW C[60]
global KinEnaAxisXX 0x20000000
global KinPosAxisXX C[29]
global KinVelAxisXX C[61]
global KinEnaAxisYY 0x40000000
global KinPosAxisYY C[30]
global KinVelAxisYY C[62]
global KinEnaAxisZZ 0x80000000
global KinPosAxisZZ C[31]
global KinVelAxisZZ C[63]
global KinAxisUsed  D[0]
global KinVelEna  D[0]
//----------------------------------------



