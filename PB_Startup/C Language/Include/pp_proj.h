
#ifndef _PP_PROJ_H_
#define _PP_PROJ_H_
//***********************************************************************************
// C header for accessing PMAC Global, CSGlobal, Ptr vars
// _PPScriptMode_ for Pmac Script like access global & csglobal
// global Mypvar - access with "Mypvar"
// global Myparray(32) - access with "Myparray(i)"
// csglobal Myqvar - access with "Myqvar(i)" where "i" is Coord #
// csglobal Myqarray(16) - access with "Myqvar(i,j)" where "j" is index
// _EnumMode_ for Pmac enum data type checking on Set & Get global functions
// Example
// global Mypvar
// csglobal Myqvar
// "SetGlobalVar(Myqvar, data)" will give a compile error because its a csglobal var.
// "SetCSGlobalVar(Mypvar, data)" will give a compile error because its a global var.
//************************************************************************************

#ifdef _PPScriptMode_
enum globalP {_globalP_=-1};
enum globalParray {_globalParray_=-1};
enum csglobalQ {_csglobalQ_=-1};
enum csglobalQarray {_csglobalQarray_=-1};

enum ptrM {_ptrM_=-1
,Ch1PlusLimit=8192
,Ch1MinusLimit=8193
,Ch1UserFlag=8194
,Ch1HomeFlag=8195
,Ch1EQU=8196
,Ch2PlusLimit=8197
,Ch2MinusLimit=8198
,Ch2UserFlag=8199
,Ch2HomeFlag=8200
,Ch2EQU=8201
,Ch3PlusLimit=8202
,Ch3MinusLimit=8203
,Ch3UserFlag=8204
,Ch3HomeFlag=8205
,Ch3EQU=8206
,Ch4PlusLimit=8207
,Ch4MinusLimit=8208
,Ch4UserFlag=8209
,Ch4HomeFlag=8210
,Ch4EQU=8211
,Ch5PlusLimit=8212
,Ch5MinusLimit=8213
,Ch5UserFlag=8214
,Ch5HomeFlag=8215
,Ch5EQU=8216
,Ch6PlusLimit=8217
,Ch6MinusLimit=8218
,Ch6UserFlag=8219
,Ch6HomeFlag=8220
,Ch6EQU=8221
,Ch7PlusLimit=8222
,Ch7MinusLimit=8223
,Ch7UserFlag=8224
,Ch7HomeFlag=8225
,Ch7EQU=8226
,Ch8PlusLimit=8227
,Ch8MinusLimit=8228
,Ch8UserFlag=8229
,Ch8HomeFlag=8230
,Ch8EQU=8231
,Enc1CountError=8232
,Enc2CountError=8233
,Enc3CountError=8234
,Enc4CountError=8235
,Enc5CountError=8236
,Enc6CountError=8237
,Enc7CountError=8238
,Enc8CountError=8239
,Enc1LossBit=8240
,Enc2LossBit=8241
,Enc3LossBit=8242
,Enc4LossBit=8243
,Enc5LossBit=8244
,Enc6LossBit=8245
,Enc7LossBit=8246
,Enc8LossBit=8247};
enum ptrMarray {_ptrMarray_=-1};
#define	Mtr1Direction	pshm->P[8192]
#define	Mtr2Direction	pshm->P[8193]
#define	Mtr3Direction	pshm->P[8194]
#define	Mtr4Direction	pshm->P[8195]
#define	Mtr5Direction	pshm->P[8196]
#define	Mtr6Direction	pshm->P[8197]
#define	Mtr7Direction	pshm->P[8198]
#define	Mtr8Direction	pshm->P[8199]
#define	DcBusInput	pshm->P[8200]
#define	Mtr1DCVoltage	pshm->P[8201]
#define	Mtr2DCVoltage	pshm->P[8202]
#define	Mtr3DCVoltage	pshm->P[8203]
#define	Mtr4DCVoltage	pshm->P[8204]
#define	Mtr5DCVoltage	pshm->P[8205]
#define	Mtr6DCVoltage	pshm->P[8206]
#define	Mtr7DCVoltage	pshm->P[8207]
#define	Mtr8DCVoltage	pshm->P[8208]
#define	Timer_axis_1	pshm->P[8209]
#define	Timer_axis_2	pshm->P[8210]
#define	Timer_axis_3	pshm->P[8211]
#define	Timer_axis_4	pshm->P[8212]
#define	Timer_axis_5	pshm->P[8213]
#define	Timer_axis_6	pshm->P[8214]
#define	Timer_axis_7	pshm->P[8215]
#define	Timer_axis_8	pshm->P[8216]
#ifndef _PP_PROJ_HDR_
  void SetEnumGlobalVar(enum globalP var, double data)
  {
    pshm->P[var] = data;
  }

  double GetEnumGlobalVar(enum globalP var)
  {
    return pshm->P[var];
  }

  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data)
  {
    pshm->P[(var + index)%MAX_P] = data;
  }

  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index)
  {
    return pshm->P[(var + index)%MAX_P];
  }

  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[var] = data;
  }

  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[var];
  }

  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q] = data;
  }

  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q];
  }

  void SetEnumPtrVar(enum ptrM var, double data)
  {
    im_write(pshm->Mdef + var, data, &pshm->Ldata);
  }

  double GetEnumPtrVar(enum ptrM var)
  {
    return im_read(pshm->Mdef + var, &pshm->Ldata);
  }

  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data)
  {
    im_write(pshm->Mdef + ((var + index)%MAX_M), data, &pshm->Ldata);
  }

  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index)
  {
    return im_read(pshm->Mdef + ((var + index)%MAX_M), &pshm->Ldata);
  }

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#else

  void SetEnumGlobalVar(enum globalP var, double data);
  double GetEnumGlobalVar(enum globalP var);
  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data);
  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index);
  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data);
  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs);
  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data);
  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs);
  void SetEnumPtrVar(enum ptrM var, double data);
  double GetEnumPtrVar(enum ptrM var);
  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data);
  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index);

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#endif
// end of #ifdef _PPScriptMode_
#else
#ifdef _EnumMode_
enum globalP {_globalP_=-1
,Mtr1Direction=8192
,Mtr2Direction=8193
,Mtr3Direction=8194
,Mtr4Direction=8195
,Mtr5Direction=8196
,Mtr6Direction=8197
,Mtr7Direction=8198
,Mtr8Direction=8199
,DcBusInput=8200
,Mtr1DCVoltage=8201
,Mtr2DCVoltage=8202
,Mtr3DCVoltage=8203
,Mtr4DCVoltage=8204
,Mtr5DCVoltage=8205
,Mtr6DCVoltage=8206
,Mtr7DCVoltage=8207
,Mtr8DCVoltage=8208
,Timer_axis_1=8209
,Timer_axis_2=8210
,Timer_axis_3=8211
,Timer_axis_4=8212
,Timer_axis_5=8213
,Timer_axis_6=8214
,Timer_axis_7=8215
,Timer_axis_8=8216};
enum globalParray {_globalParray_=-1};
enum csglobalQ {_csglobalQ_=-1};
enum csglobalQarray {_csglobalQarray_=-1};
enum ptrM {_ptrM_=-1
,Ch1PlusLimit=8192
,Ch1MinusLimit=8193
,Ch1UserFlag=8194
,Ch1HomeFlag=8195
,Ch1EQU=8196
,Ch2PlusLimit=8197
,Ch2MinusLimit=8198
,Ch2UserFlag=8199
,Ch2HomeFlag=8200
,Ch2EQU=8201
,Ch3PlusLimit=8202
,Ch3MinusLimit=8203
,Ch3UserFlag=8204
,Ch3HomeFlag=8205
,Ch3EQU=8206
,Ch4PlusLimit=8207
,Ch4MinusLimit=8208
,Ch4UserFlag=8209
,Ch4HomeFlag=8210
,Ch4EQU=8211
,Ch5PlusLimit=8212
,Ch5MinusLimit=8213
,Ch5UserFlag=8214
,Ch5HomeFlag=8215
,Ch5EQU=8216
,Ch6PlusLimit=8217
,Ch6MinusLimit=8218
,Ch6UserFlag=8219
,Ch6HomeFlag=8220
,Ch6EQU=8221
,Ch7PlusLimit=8222
,Ch7MinusLimit=8223
,Ch7UserFlag=8224
,Ch7HomeFlag=8225
,Ch7EQU=8226
,Ch8PlusLimit=8227
,Ch8MinusLimit=8228
,Ch8UserFlag=8229
,Ch8HomeFlag=8230
,Ch8EQU=8231
,Enc1CountError=8232
,Enc2CountError=8233
,Enc3CountError=8234
,Enc4CountError=8235
,Enc5CountError=8236
,Enc6CountError=8237
,Enc7CountError=8238
,Enc8CountError=8239
,Enc1LossBit=8240
,Enc2LossBit=8241
,Enc3LossBit=8242
,Enc4LossBit=8243
,Enc5LossBit=8244
,Enc6LossBit=8245
,Enc7LossBit=8246
,Enc8LossBit=8247};
enum ptrMarray {_ptrMarray_=-1};
#ifndef _PP_PROJ_HDR_
  void SetEnumGlobalVar(enum globalP var, double data)
  {
    pshm->P[var] = data;
  }

  double GetEnumGlobalVar(enum globalP var)
  {
    return pshm->P[var];
  }

  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data)
  {
    pshm->P[(var + index)%MAX_P] = data;
  }

  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index)
  {
    return pshm->P[(var + index)%MAX_P];
  }

  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[var] = data;
  }

  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[var];
  }

  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q] = data;
  }

  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q];
  }

  void SetEnumPtrVar(enum ptrM var, double data)
  {
    im_write(pshm->Mdef + var, data, &pshm->Ldata);
  }

  double GetEnumPtrVar(enum ptrM var)
  {
    return im_read(pshm->Mdef + var, &pshm->Ldata);
  }

  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data)
  {
    im_write(pshm->Mdef + ((var + index)%MAX_M), data, &pshm->Ldata);
  }

  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index)
  {
    return im_read(pshm->Mdef + ((var + index)%MAX_M), &pshm->Ldata);
  }

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#else

  void SetEnumGlobalVar(enum globalP var, double data);
  double GetEnumGlobalVar(enum globalP var);
  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data);
  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index);
  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data);
  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs);
  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data);
  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs);
  void SetEnumPtrVar(enum ptrM var, double data);
  double GetEnumPtrVar(enum ptrM var);
  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data);
  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index);

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#endif
// end of #ifdef _EnumMode_
#else
// ***** Standard default mode *****
#define Mtr1Direction 8192
#define Mtr2Direction 8193
#define Mtr3Direction 8194
#define Mtr4Direction 8195
#define Mtr5Direction 8196
#define Mtr6Direction 8197
#define Mtr7Direction 8198
#define Mtr8Direction 8199
#define Ch1PlusLimit 8192
#define Ch1MinusLimit 8193
#define Ch1UserFlag 8194
#define Ch1HomeFlag 8195
#define Ch1EQU 8196
#define Ch2PlusLimit 8197
#define Ch2MinusLimit 8198
#define Ch2UserFlag 8199
#define Ch2HomeFlag 8200
#define Ch2EQU 8201
#define Ch3PlusLimit 8202
#define Ch3MinusLimit 8203
#define Ch3UserFlag 8204
#define Ch3HomeFlag 8205
#define Ch3EQU 8206
#define Ch4PlusLimit 8207
#define Ch4MinusLimit 8208
#define Ch4UserFlag 8209
#define Ch4HomeFlag 8210
#define Ch4EQU 8211
#define Ch5PlusLimit 8212
#define Ch5MinusLimit 8213
#define Ch5UserFlag 8214
#define Ch5HomeFlag 8215
#define Ch5EQU 8216
#define Ch6PlusLimit 8217
#define Ch6MinusLimit 8218
#define Ch6UserFlag 8219
#define Ch6HomeFlag 8220
#define Ch6EQU 8221
#define Ch7PlusLimit 8222
#define Ch7MinusLimit 8223
#define Ch7UserFlag 8224
#define Ch7HomeFlag 8225
#define Ch7EQU 8226
#define Ch8PlusLimit 8227
#define Ch8MinusLimit 8228
#define Ch8UserFlag 8229
#define Ch8HomeFlag 8230
#define Ch8EQU 8231
#define DcBusInput 8200
#define Mtr1DCVoltage 8201
#define Mtr2DCVoltage 8202
#define Mtr3DCVoltage 8203
#define Mtr4DCVoltage 8204
#define Mtr5DCVoltage 8205
#define Mtr6DCVoltage 8206
#define Mtr7DCVoltage 8207
#define Mtr8DCVoltage 8208
#define Enc1CountError 8232
#define Enc2CountError 8233
#define Enc3CountError 8234
#define Enc4CountError 8235
#define Enc5CountError 8236
#define Enc6CountError 8237
#define Enc7CountError 8238
#define Enc8CountError 8239
#define Enc1LossBit 8240
#define Enc2LossBit 8241
#define Enc3LossBit 8242
#define Enc4LossBit 8243
#define Enc5LossBit 8244
#define Enc6LossBit 8245
#define Enc7LossBit 8246
#define Enc8LossBit 8247
#define Timer_axis_1 8209
#define Timer_axis_2 8210
#define Timer_axis_3 8211
#define Timer_axis_4 8212
#define Timer_axis_5 8213
#define Timer_axis_6 8214
#define Timer_axis_7 8215
#define Timer_axis_8 8216
#endif
#endif
#endif //_PP_PROJ_H_
