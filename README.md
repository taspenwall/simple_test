I started programming in C a few months ago and quickly fell in love with the ATtiny for its simplicity and as an entry into low-level programming. I wanted to learn more about GDB, so I started exploring simulation and debugging. Thinking that simulating an interrupt and stepping into an ISR would be an easy task, I decided to give it a try even if it might be impratical.

I’ve managed to get a small program to compile for both platforms and have been successful in connecting GDB to step through my program. I’m also able to stop the simulation and execute some steps where I would be triggering the interrupt, then go back to GDB to continue debugging. I used button.h/.c and board_rotenc as guides on how to program an IRQ to trigger an interrupt. Although it's a bit over my head, I think I’m starting to get close.

I’m still unclear on whether I need to define the interrupt further and how exactly allocating the IRQ will specify the interrupt vector to use. I've posted my project to my GitHub. The directory structure is having the simavr repo in a folder next to my project.This requires a change in line 182 in Makefile.common.   Other than that, it should compile with an untouched simavr repo. I've tried to keep everything as simple as possible.

I know that trying to step into an ISR while debugging with an interrupt may seem like a waste of time to some, but given what I have learned so far, it’s been a great project. It’s more about the journey than the destination. If you have some time and are willing to help out a budding programmer, I’d really appreciate it.



