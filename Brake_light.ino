
#include <mcp_can.h>
#include <SPI.h>
#include <mcp_can_dfs.h>

long unsigned rxId;
unsigned char len;
byte rxBuf[8];
long unsigned int rxId2;
unsigned char len2;
byte rxBuf2[8];

MCP_CAN CAN0(9);

void setup()
{
  Serial.begin(115200);
  
  CAN0.begin(MCP_STDEXT, CAN_1000KBPS, MCP_8MHZ);
  

  CAN0.init_Mask(0,1,0x000FFFFF);                // Init first mask...
  CAN0.init_Filt(0,1,0x000F1906);                // Init first filter...
  CAN0.init_Filt(1,1,0x000F1906);                // Init second filter...

  
  CAN0.init_Mask(1,1,0x000FFFFF);                // Init second mask...
  CAN0.init_Filt(2,1,0x000F1906);                // Init third filter...
  CAN0.init_Filt(3,1,0x000F1906);                // Init fourth filter...
  CAN0.init_Filt(4,1,0x000F1906);                // Init fifth filter...
  CAN0.init_Filt(5,1,0x000F1906);                // Init sixth filter...



  CAN0.setMode(MCP_NORMAL);                     // Set operation mode to normal so the MCP2515 sends acks to received data.

  pinMode (1, OUTPUT);
  digitalWrite(1, LOW);
}

void loop()
{

  CAN0.readMsgBuf(&rxId, &len, rxBuf);
  
  
      if (rxBuf[0] != 0)
     digitalWrite(1, HIGH);
      else
      digitalWrite(1, LOW);
  
  
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
