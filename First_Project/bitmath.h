#define set_bit(var,pos)         var|=(1<<pos)
#define reset_bit(var,pos)      var&=(~(1<<pos))
#define toggle_bit(var,pos)         var^=1<<pos
#define read_bit(var,pos)           var=var>>pos&1





