#pragma once
#ifndef _COMPOSANT5_H

//
// composant5.h  version 1.0
//
// projet blockchain M2IF 2016
//

#include "bloc.h"
#include <string> 
using namespace std;

bool blockVerify(Bloc bloc, string chainAES);
bool transfertVerify(TX t, string chainAES);

#endif