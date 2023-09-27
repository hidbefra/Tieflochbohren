BEGIN PGM TIEFBOHREN MM 
;23.04.2018 F.Hidber getestet

CYCL DEF 7.0 NULLPUNKT
CYCL DEF 7.1  Z+Q203

L Z+Q200 R0 FMAX ;VORPOSS
TOOL CALL  SQ427 ;DREHZAHL VORPOSS
L Z-Q379 R0 FQ253 ;OBEN
TOOL CALL  SQ428 ;VC

;ERSTER HUB
QL3 = Q202 ;INK BOHRTIEFE
QL1=-Q379 ;AKTUELE BOHRTIEFE
CALL LBL 30

LBL 2 ;Bohren
QL3=QL3-Q212 ;INK. BOHRTIEFE
FN 11: IF +QL3 GT +Q205 GOTO LBL 13 ;PRUEFEN OB MIN INK.
QL3=Q205
LBL 13

QL2=QL1+Q258 ;VORPOSITION
L Z+QL2 R0 FQ208 ;VORPOSS

LBL 30
QL1= QL1-QL3 ;BOHRTIEFE
FN 11: IF +QL1 GT +Q201 GOTO LBL 12 ;PRUEFEN OB ENDTIEFE
QL1 = Q201
LBL 12

L Z+QL1 R0 FQ206 ;BOHREN
CYCL DEF 9.0 VERWEILZEIT
CYCL DEF 9.1 V.ZEIT Q211
L Z-Q379 R0 FQ208 ;RUECKZUG
FN 10: IF +QL1 NE +Q201 GOTO LBL 2 ;WIEDERHOLEN BIS ENDTIEFE

;ENDE
TOOL CALL  SQ427 ;DREHZAHL VORPOSS
CYCL DEF 9.0 VERWEILZEIT
CYCL DEF 9.1 V.ZEIT 2
L Z-Q379 R0 FQ208 ;RUECKZUG
L Z+Q204 R0 FMAX ;SICHERE HOEHE

CYCL DEF 7.0 NULLPUNKT
CYCL DEF 7.1  Z0

END PGM TIEFBOHREN MM 