        asm {

;
; Scan For Minds
;


              LDA character_px
			  SEC
			  SBC #47
			  LSR
			  LSR 
			  STA a
			  
              LDA character_py
			  SEC
			  SBC #24
			  LSR
			  LSR 
			  LSR
			  STA b

              LDA #0
              STA g 
              LDY b
              CPY #26
              BCS Scan_For_restore_Beyond_Screen
              DEY
              DEY                
              STY h
              BPL No_0_First_restore_Row
              LDY #0
No_0_First_restore_Row
                
              LDA A
              SEC
              SBC #2
              CLC
              ADC adr.screen_row_low,Y
              STA NDX0
              LDA adr.screen_row_high,Y
              ADC #0
              STA NDX1
Scan_restore_Row_Start   
              LDA h
              BMI Skip_restore_Scan_Row
              CMP #26
              BCS Skip_restore_Scan_Row                           
              LDY #5
Scan_For_restore_Loop                          
              LDA (NDX0),Y
              CMP #65 
              BNE No_restore_Found
              LDA #193
              STA (NDX0),Y
No_restore_Found
              DEY
              BPL Scan_For_restore_Loop

              LDA ndx0
              CLC
              ADC #40 ; or 48 if widescren
              STA ndx0
              BCC SM_L2
              INC ndx1
SM_L2        

Skip_restore_Scan_Row
              LDY g
              INY
              CPY #5
              STY g
              BCS Scan_For_restore_Beyond_Screen
              INC h 
              JMP Scan_restore_Row_Start                                             
Scan_For_restore_Beyond_Screen                                            
                                            
                                                                                      
};                                      



			asm {																		            						            			
			  LDA porta
			  AND #15
			  


              LDA character_px
			  SEC
			  SBC #47
			  LSR
			  LSR 
			  STA a
			  
              LDA character_py
			  SEC
			  SBC #24
			  LSR
			  LSR 
			  LSR
			  STA b
			    
              LDA #202
              STA colpm0
              LDA #0
              STA g
              STA minds_found 
              LDY b
              CPY #26
              BCS Scan_For_Mind_Beyond_Screen
              DEY
              DEY                
              STY h
              BPL No_0_First_Mind_Row
              LDY #0
No_0_First_Mind_Row
                
              LDA A
              SEC
              SBC #2
              CLC
              ADC adr.screen_row_low,Y
              STA NDX0
              LDA adr.screen_row_high,Y
              ADC #0
              STA NDX1
Scan_Mind_Row_Start   
              LDA h
              BMI Skip_Mind_Scan_Row
              CMP #26
              BCS Skip_Mind_Scan_Row                           
              LDY #5
Scan_For_Mind_Loop                          
              LDA (NDX0),Y
              CMP #193
              BNE No_Mind_Found
              LDA #65
              STA (NDX0),Y
              INC minds_found
ChecK_Mind_Column
              CPY #3
              BEQ ChecK_Mind_Row
              CPY #2
              BNE No_Mind_Found
ChecK_Mind_Row
              LDA g
              CMP #1
              BEQ Mind_Under_Character
              CMP #2
              BNE No_Mind_Found
Mind_Under_Character
               LDA #15
               STA colpm0
No_Mind_Found
              DEY
              BPL Scan_For_Mind_Loop

              LDA ndx0
              CLC
              ADC #40 ; or 48 if widescren
              STA ndx0
              BCC SM_L4
              INC ndx1
SM_L4         

Skip_Mind_Scan_Row
              LDY g
              INY
              CPY #5
              STY g
              BCS Scan_For_Mind_Beyond_Screen
              INC h 
              JMP Scan_Mind_Row_Start                                             
Scan_For_Mind_Beyond_Screen                                            
