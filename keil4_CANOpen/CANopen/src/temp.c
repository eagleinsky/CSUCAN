#include "data.h"

/*states.c*/
//void _initialisation(CO_Data* d){}
//void _preOperational(CO_Data* d){}
//void _operational(CO_Data* d){}
//void _stopped(CO_Data* d){}

	
//lifegrd.c

void _heartbeatError(CO_Data* d, UNS8 heartbeatID){}
void _post_SlaveBootup(CO_Data* d, UNS8 SlaveID){}
void _post_SlaveStateChange(CO_Data* d, UNS8 nodeId, e_nodeState newNodeState){}
void _nodeguardError(CO_Data* d, UNS8 id){}
	
	
//	nmtSlave.c (src):
void proceedNMTstateChange(CO_Data* d, Message *m) {}

//Sdo.c (src):
UNS8 proceedSDO (CO_Data* d, Message *m) {}
	
//nmtMaster.c (src):
UNS8 masterSendNMTstateChange(CO_Data* d, UNS8 Node_ID, UNS8 cs) {}

	