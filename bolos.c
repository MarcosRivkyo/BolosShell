 /*======================================================================================
 ========================================================================================
 === SEGUNDO TRABAJO SISTEMAS OPERATIVOS I: BOLOS ===================
 ========================================================================================
 === TRABAJO REALIZADO POR: Marcos Rivas Kyoguro GRUPO: PB2 ===================
 ======================================================================================*/

 #define _HPUX_SOURCE
0
11 #include<unistd.h>
12 #include<stdio.h>
13 #include<signal.h>
14 #include<sys/wait.h>
15 #include<sys/time.h>
16 #include<string.h>
17 #include<stdlib.h>
18
19 /*=======================================================================================================
20 ==============
21 INTÉRPRETE DE LAS SEÑALES \\\ DETERMINA QUE FUNCION TOMAN LOS PROCESOS Y ENVIA LA SEÑAL
22 SIGTERM ==
23 ==
24 1-No envia la señal a ningún proceso. ==
25 2-Envia la señal al proceso situado debajo a la derecha. ==
26 3-Envia la señal al proceso situado debajo a la izquierda. ==
27 4-Envia la señal a ambos procesos. ==
28 =========================================================================================================
29 ==============*/
30
31 int signals(char *argv[]){
32
33 int left_side,right_side;
34
35 struct timeval start;
36
37
38 if(strcmp(argv[2],"0")==0){ //Si no recibe ningun pid como parametro no
39 trabaja
40
41 return -1;
42 }
43
44
45
46 else{
47 int temp;
48
49 left_side=atoi(argv[1]);
50
51 right_side=atoi(argv[2]);
52
53 gettimeofday(&start,NULL); //Obtengo el tiempo en el reloj del ordenador
54
55 temp= start.tv_usec%4; //Obtengo el módulo del tiempo entre 4
56
57
58 if(temp==0) { //No envia la señal a ningún proceso.
59
60 return 0;
61 }
62
63
64 else if(temp==1){ //Enviar la señal al proceso situado debajo a la
65 derecha.
66 kill(right_side,SIGTERM);
67 return 1;
68 }
69
70
71 else if(temp==2){ //Enviar la señal al proceso situado debajo a la
72 izquierda.
73 kill(left_side,SIGTERM);
74 return 2;
75 }
76
77
78 else if(temp==3){ //Enviar la señal a ambos procesos
79 kill(right_side,SIGTERM);
80 kill(left_side,SIGTERM);
81 return 3;
82
83 }
84
85 }
86
87 }
88
89 //===================
90 //SIGNAL_HANDLER ====
91 //===================
92
93 void handler(int ss){
94
95 }
96
97 //=================================
98 //MOSTRAR ÁRBOL DE PROCESOS =======
99 //=================================
100
101 void arbolDeProcesos(int valorB,int valorC,int valorE,int valorH,int valorI){
102
103 char c0, c1, c2, c3, c4, c5, c6, c7, c8, c9;
104
105 //SÍMOBLO DEL PROCESO B
106
107 if(valorB>0){
108 c0='+';}
109 else{
110 c0='B';}
111 //SÍMBOLO DEL PROCESO C
112
113 if(valorC>0){
114 c1='+';}
115 else {
116 c1='C';}
117 //SÍMBOLO DEL PROCESO D
118
119 if(valorB>1){
120 c2='+';}
121 else {
122 c2='D';}
123 //SÍMBOLO DEL PROCESO E
124
125 if(valorE>0){
126 c3='+';}
127 else{
128 c3='E'; }
129 //SÍMBOLO DEL PROCESO F
130
131 if(valorC>1){
132 c4='+';}
133 else{
134 c4='F';}
135 //SÍMBOLO DEL PROCESO G
136
137 if(valorB>2){
138 c5='+';}
139 else{
140 c5='G';}
141 //SÍMBOLO DEL PROCESO H
142
143 if(valorH>0){
144 c6='+';}
145 else{
146 c6='H';}
147 //SÍMBOLO DEL PROCESO I
148
149 if(valorI>0){
150 c7='+';}
151 else{
152 c7='I';}
153 //SÍMBOLO DEL PROCESO J
154
155 if(valorC>2){
156 c8='+';}
157 else {
158 c8='J';}
159
160
161
162 fprintf(stdout,"\n\n=========================================================================
163 =");
164 fprintf(stdout,"\n===================================BOLOS=================================="
165 );
166 fprintf(stdout,"\n==========================================================================\
167 n\n");
168
169
170 fprintf(stdout,"\n||\t\t\t (+) \t\t||\n");
171
172 fprintf(stdout,"\n||\t\t (%c) (%c) \t\t||\n", c0,c1);
173
174 fprintf(stdout,"\n||\t\t (%c) (%c) (%c) \t\t||\n",c2,c3,c4);
175
176 fprintf(stdout,"\n||\t\t (%c) (%c) (%c) (%c) \t\t||\n",c5,c6,c7,c8);
177
178
179 fprintf(stdout,"\n==========================================================================");
180
181 fprintf(stdout,"\n==========================================================================");
182
183 printf("\n\n");
184
185 }
186
187 //===============
188 //Funcion MAIN
189 //===============
190
191 int main(int argc,char *argv[]){
192
193 pid_t pid_A, pid_B, pid_C, pid_D, pid_E, pid_F, pid_G, pid_H, pid_I, pid_J; //pid's de los procesos
194
195 char pid_1[10],pid_2[10],pid_3[10],pid_4[10],pid_5[10];
196 //pid's que se pasan por paramtro en el execlp
197
198 int proc1,proc2,proc3,proc4,proc5;
199
200 int valorB=0, valorC=0,valorD=0, valorE=0,valorF=0,vG=0, valorH=0, valorI=0,valorJ=0;
201
202 int retorno;
203
204
205 /*if(argc != 2)
206 {
207 fprintf(stderr,"Uso: %s\n\n",argv[0]);
208 return 1;
209 }*/
210
211
212
213
214 if(strcmp("./bolos",argv[0])==0){ //Se crea el comienzo del programa que creará el hijo A
215
216 switch (pid_A=fork())
217 {
218 case -1:
219 perror("Problema_encontrado");
220 return -1;
221 break;
222
223
224 case 0:
225 execlp("./bolos","./COMIENZO",NULL);
226 break;
227
228
229 default:
230 break;
231
232
233 }
234 }
235
236
237 if(strcmp("./COMIENZO",argv[0])==0){ //Comienza la creación de los procesos
238 switch (pid_I=fork())
239 {
240 case -1:
241 perror("Problema_encontrado");
242 return -1;
243 break;
244
245
246 case 0:
247 execlp("./bolos","I","0","0",NULL);
248 break;
249
250
251 default:
252 switch (pid_H=fork())
253 {
254 case -1:
255 perror("Problema_encontrado");
256 return -1;
257 break;
258
259 case 0:
260 execlp("./bolos","H","0","0",NULL);
261 break;
262
263 default:
264 switch (pid_E=fork())
265 {
266 case -1:
267 perror("Problema_encontrado");
268 return -1;
269 break;
270
271 case 0:
272 sprintf(pid_1,"%d",pid_H);
273 sprintf(pid_2,"%d",pid_I);
274 execlp("./bolos","E",pid_1,pid_2,NULL);
275 break;
276
277 default:
278
279 switch (pid_B=fork())
280 {
281 case -1:
282 perror("Problema_encontrado");
283 return -1;
284 break;
285
286 case 0:
287 switch (pid_D=fork())
288 {
289
290 case -1:
291 perror("Problema_encontrado");
292 return -1;
293 break;
294
295 case 0:
296 switch (pid_G=fork())
297 {
298 case -1:
299 perror("Problema_encontrado");
300 return -1;
301 break;
302
303 case 0:
304
305 execlp("./bolos","G","0","0",NULL);
306 break;
307
308 default:
309
310 sprintf(pid_1,"%d",pid_G);
311 sprintf(pid_2,"%d",pid_H);
312 execlp("./bolos","D",pid_1,pid_2,NULL);
313 break;
314 }
315 break;
316
317 default:
318 sprintf(pid_1,"%d",pid_D);
319 sprintf(pid_2,"%d",pid_E);
320 execlp("./bolos","B",pid_1,pid_2,NULL);
321 break;
322 }
323
324 break;
325
326
327 default:
328 switch (pid_C=fork())
329 {
330
331 case -1:
332 perror("Problema_encontrado");
333 return -1;
334 break;
335
336 case 0:
337 switch (pid_F=fork())
338 {
339 case -1:
340 perror("Problema_encontrado");
341 return -1;
342 break;
343
344 case 0:
345 switch (pid_J=fork())
346 {
347 case -1:
348 perror("Problema_encontrado"); return
349 -1;
350 break;
351
352 case 0:
353 execlp("./bolos","J","0","0",NULL);
354
355 default:
356 sprintf(pid_1,"%d",pid_I);
357 sprintf(pid_2,"%d",pid_J);
358 execlp("./bolos","F",pid_1,pid_2,NULL
359 );
360 break;
361 }
362
363 break;
364
365 default:
366 sprintf(pid_1,"%d",pid_E);
367 sprintf(pid_2,"%d",pid_F);
368 execlp("./bolos","C",pid_1,pid_2,NULL);
369
370 break;
371 }
372 break;
373 }
374 break;
375 }
376 break;
377 }
378 break;
379 }
380 break;
381 }
382 }
383
384
385 if(strcmp("./COMIENZO",argv[0])==0){ //Lo separo en dos funciones
386
387 sprintf(pid_1,"%d",pid_B);
388
389 sprintf(pid_2,"%d",pid_C);
390
391 sprintf(pid_3,"%d",pid_E);
392
393 sprintf(pid_4,"%d",pid_H);
394
395 sprintf(pid_5,"%d",pid_I);
396
397 execlp("./bolos","A",pid_1,pid_2,pid_3,pid_4,pid_5,NULL);
398 }
399
400
401
402 struct sigaction ss;
403 sigset_t set;
404 sigfillset(&set);
405 ss.sa_handler=handler;
406 ss.sa_mask=set;
407 ss.sa_flags=0;
408
409
410 sigaction(SIGTERM,&ss,NULL);
411
412
413 if(strcmp("A",argv[0])==0){ //Si recibe el proceso A
414
415 fprintf(stdout,"\nPID DEL PROCESO : %d\n",getpid());
416
417 pause();
418
419 retorno=signals(argv);
420
421 sleep(4);
422
423
424 proc1=atoi(argv[1]);
425 proc3=atoi(argv[3]);
426 proc4=atoi(argv[4]);
427 proc2=atoi(argv[2]);
428 proc5=atoi(argv[5]);
429
430 if(retorno==2){ //LADO IZQUIERDO
431 waitpid(proc1,&valorB,0);
432
433 valorB=WEXITSTATUS(valorB);
434
435 }else if(retorno==1){ //LADO DERECHO
436 waitpid(proc2,&valorC,0);
437
438 valorC=WEXITSTATUS(valorC);
439
440 }else if(retorno==3){ //AMBOS LADOS
441
442 waitpid(proc1,&valorB,0); //1ºproceso
443
444 valorB=WEXITSTATUS(valorB);
445
446 waitpid(proc2,&valorC,0); //2ºproceso
447
448 valorC=WEXITSTATUS(valorC);
449
450 }
451
452 waitpid(proc3,&valorE,WNOHANG); //3ºproceso
453
454 if(valorE!=0){
455 valorE=WEXITSTATUS(valorE);
456 }
457
458 waitpid(proc4,&valorH,WNOHANG); //4ºproceso
459
460 if(valorH!=0){
461 valorH=WEXITSTATUS(valorH);
462 }
463
464
465 waitpid(proc5,&valorI,WNOHANG); //5ºproceso
466
467 if(valorI!=0){
468 valorI=WEXITSTATUS(valorI);
469 }
470
471
472 arbolDeProcesos(valorB,valorC,valorE,valorH,valorI); //Se muestra el árbol del procesos
473
474
475 switch (fork()) //Se ejecuta ps -fu por medio de un hijo de A y execlp
476 {
477
478 case -1:
479 perror("Problema_Encontrado");
480 return -1;
481 break;
482
483
484 case 0:
485 execlp("ps","ps","-fu", getenv("USER") ,NULL); //con getenv(“USER”) obtenemos el nombre del
486 usuario
487
488 break;
489
490 default:
491 wait(NULL);
492 kill(0,SIGTERM); //MATa AL HIJO PS -FU
493 break;
494
495
496
497 }
498 fprintf(stdout,"\n==========================================================================");
499 fprintf(stdout,"\n==========================================================================");
500 fprintf(stdout,"\n<<PULSE ENTER PARA CONTINUAR>>");
501
502 fprintf(stdout,"\n\n"); //FIN DEL PROGRAMA
503
504 }
505
506
507 else if(strcmp("B",argv[0])==0){ //Si recibe el proceso B
508
509 pause();
510
511 retorno=signals(argv);
512
513 proc1=atoi(argv[1]);
514
515
516 if (retorno==3 || retorno==2){ //Si elimina izquierda o ambos
517
518 wait(&valorD);
519 exit( WEXITSTATUS(valorD)+1); //Si se elimina aumento valorD para poder
520 saber en la funcion arbolDeProcesos qué procesos están vivos y no
521
522 }
523 exit(1);
524 }
525
526
527 else if(strcmp("C",argv[0])==0){ //Si recibe el proceso C
528 pause();
529
530 retorno=signals(argv);
531
532 proc1=atoi(argv[2]);
533
534 if (retorno==1 || retorno==3){ //Si elimina derecha o ambos
535
536 wait(&valorF);
537 exit( WEXITSTATUS(valorF)+1);
538 }
539 exit(1);
540 }
541
542
543
544 else if(strcmp("D",argv[0])==0){ //Si recibe el proceso D
545 pause();
546
547 retorno=signals(argv);
548
549 proc1=atoi(argv[1]);
550
551 if (retorno==2 || retorno==3){ //Si elimina izquierda o ambos
552
553 wait(&vG);
554 exit( WEXITSTATUS(vG)+1);
555 }
556 exit(1);
557 }
558
559
560
561 else if(strcmp("E",argv[0])==0){ //Si recibe el proceso E
562 pause();
563
564 retorno=signals(argv); //Es un extremon, no elimina
565
566 exit(1);
567
568 }
569
570
571 else if(strcmp("F",argv[0])==0){ //Si recibe el proceso F
572 pause();
573
574 retorno=signals(argv);
575
576 proc1=atoi(argv[2]);
577
578 if (retorno==1 || retorno==3){ //Si elimina izquierda o ambos
579
580 wait(&valorJ);
581 exit( WEXITSTATUS(valorJ)+1);
582 }
583 exit(1);
584 }
585
586
587
588 else if(strcmp("I",argv[0])==0){ //Si recibe el proceso I
589 pause();
590
591 retorno=signals(argv); //Es un extremon, no elimina
592
593 exit(1);
594 }
595
596
597 else if(strcmp("J",argv[0])==0){ //Si recibe el proceso J
598 pause();
599
600 retorno=signals(argv); //Es un extremon, no elimina
601
602 exit(1);
603 }
604
605 else if(strcmp("G",argv[0])==0){ //Si recibe el proceso G
606 pause();
607
608 retorno=signals(argv); //Es un extremon, no elimina
609
610 exit(1);
611 }
612
613
614 else if(strcmp("H",argv[0])==0){ //Si recibe el proceso H
615 pause();
616
617 retorno=signals(argv); //Es un extremon, no elimina
618
619 exit(1);
620 }
621
622
623 }
624
625
