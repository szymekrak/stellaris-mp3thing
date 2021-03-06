void drawLines(unsigned char x, unsigned short int y)
{
  LCD_VerLine(y-5,y+5,x,RED);
  LCD_HorLine(x-5,x+5,y,RED);
}
void cleanLines(unsigned char x, unsigned short int y)
{
  LCD_VerLine(y-5,y+5,x,GREEN);
  LCD_HorLine(x-5,x+5,y,GREEN);
}

void appCalibrate()
{
  int xdata1,xdata2,ydata1,ydata2;
  LCD_Clear(BLUE);
  LCD_DrawString(appCalibrateName,64, 150, BLACK);
  drawLines(10,10);
  while(!touchPressed);
  delay(100);
  xdata1=touch_SreadXData();
  delay(100);
  xdata1+=touch_SreadXData();
  delay(100);
  xdata1+=touch_SreadXData();
  delay(100);
  xdata1+=touch_SreadXData();
  delay(100);
  xdata1+=touch_SreadXData();
  delay(100);
  ydata1=touch_SreadYData();
  delay(100);
  ydata1+=touch_SreadYData();
  delay(100);
  ydata1+=touch_SreadYData();
  delay(100);
  ydata1+=touch_SreadYData();
  delay(100);
  ydata1+=touch_readYData();
  cleanLines(10,10);
  while(touchPressed);
  delay(200);
  
  drawLines(229,10);
  while(!touchPressed);
  delay(100);
  xdata2+=touch_SreadXData();
  delay(100);
  xdata2+=touch_SreadXData();
  delay(100);
  xdata2+=touch_SreadXData();
  delay(100);
  xdata2+=touch_SreadXData();
  delay(100);
  xdata2+=touch_SreadXData();
  delay(100);
  ydata1+=touch_SreadYData();
  delay(100);
  ydata1+=touch_SreadYData();
  delay(100);
  ydata1+=touch_SreadYData();
  delay(100);
  ydata1+=touch_SreadYData();
  delay(100);
  ydata1+=touch_readYData();
  cleanLines(229,10);
  while(touchPressed);
  delay(200);
  
  drawLines(10,309);
  while(!touchPressed);
  delay(100);
  xdata1+=touch_SreadXData();
  delay(100);
  xdata1+=touch_SreadXData();
  delay(100);
  xdata1+=touch_SreadXData();
  delay(100);
  xdata1+=touch_SreadXData();
  delay(100);
  xdata1+=touch_SreadXData();
  delay(100);
  ydata2+=touch_SreadYData();
  delay(100);
  ydata2+=touch_SreadYData();
  delay(100);
  ydata2+=touch_SreadYData();
  delay(100);
  ydata2+=touch_SreadYData();
  delay(100);
  ydata2+=touch_readYData();
  cleanLines(10,309);
  while(touchPressed);
  delay(200);
  
  drawLines(229,309);
  while(!touchPressed);
  delay(100);
  xdata2+=touch_SreadXData();
  delay(100);
  xdata2+=touch_SreadXData();
  delay(100);
  xdata2+=touch_SreadXData();
  delay(100);
  xdata2+=touch_SreadXData();
  delay(100);
  xdata2+=touch_SreadXData();
  delay(100);
  ydata2+=touch_SreadYData();
  delay(100);
  ydata2+=touch_SreadYData();
  delay(100);
  ydata2+=touch_SreadYData();
  delay(100);
  ydata2+=touch_SreadYData();
  delay(100);
  ydata2+=touch_readYData();
  cleanLines(229,309);
  LCD_Clear(BLUE);
  LCD_DrawString(appCalibrateDone,64, 150, BLACK);
  while(touchPressed);
  touchSetCalibration(xdata1/10,xdata2/10,ydata1/10,ydata2/10);
  long unsigned int tt[5];
  tt[0]=0xC0FFEE;
  tt[1]=xdata1/10;
  tt[2]=xdata2/10;
  tt[3]=ydata1/10;
  tt[4]=ydata2/10;
  ROM_EEPROMProgram(tt,0,20);
}
