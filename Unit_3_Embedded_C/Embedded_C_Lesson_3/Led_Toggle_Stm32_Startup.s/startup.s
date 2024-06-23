//startup_CortexM3..... Eng/Mina saad
.section .vectors

.word  stack_top                 //loading value for sp
.word _reset
.word vector_handler              
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler



.section .text
_reset:
        bl main
        b .
.thumb_func
vector_handler:
        b _reset



