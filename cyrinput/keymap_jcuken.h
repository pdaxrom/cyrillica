/*
 *	keymap for SL-C700 hardware keyboard
 *	ru/be/uk JCUKEN layout
 *
 */
typedef struct _kbdecode {
    int		keycode;
    ushort	unicode;
    ushort	bunicode;
} kbdecode;

#if (SLC700 == 1)
kbdecode hkeymap [][44] = { 
//russia
    {
	{ '1', '!', '1' },
	{ '2', '"', '2' },
	{ '3', 0x2116, '3' },
	{ '4', ';', '4' },
	{ '5', ':', '5' },
	{ '6', ',', '6' },
	{ '7', '.', '7' },
	{ '8', '(', '8' },
	{ '9', ')', '9' },
	{ '0', '?', '0' },

	{ 'Q', 0x419, 0x439 },
	{ 'W', 0x426, 0x446 },
	{ 'E', 0x423, 0x443 },
	{ 'R', 0x41a, 0x43a },
	{ 'T', 0x415, 0x435 },
	{ 'Y', 0x41d, 0x43d },
	{ 'U', 0x413, 0x433 },
	{ 'I', 0x428, 0x448 },
	{ 'O', 0x429, 0x449 },
	{ 'P', 0x417, 0x437 },
	
	{ 'A', 0x424, 0x444 },
	{ 'S', 0x42b, 0x44b },
	{ 'D', 0x412, 0x432 },
	{ 'F', 0x410, 0x430 },
	{ 'G', 0x41f, 0x43f },
	{ 'H', 0x420, 0x440 },
	{ 'J', 0x41e, 0x43e },
	{ 'K', 0x41b, 0x43b },
	{ 'L', 0x414, 0x434 },
	
	{ 'Z', 0x42f, 0x44f },
	{ 'X', 0x427, 0x447 },
	{ 'C', 0x421, 0x441 },
	{ 'V', 0x41c, 0x43c },
	{ 'B', 0x418, 0x438 },
	{ 'N', 0x422, 0x442 },
	{ 'M', 0x42c, 0x44c },
	
	{ 0x1049, 0x425, 0x445 },
	{ 0x1044, 0x42a, 0x44a },
	{ '-', 0x42d, 0x44d },
	{ ',', 0x411, 0x431 },
	{ '.', 0x42e, 0x44e },
	{ '/', 0x411, 0x411 },
	{ '?', 0x42e, 0x42e },

//	{ '@', 0x42d, 0x44d },
//	{ '<', 0x416, 0x436 },
//	{ '>', 0x401, 0x451 },
//	{ '{', 0x416, 0x416 },
//	{ '}', 0x401, 0x401 },

	{0,0,0}
    },
//makedonia
    {
	{ '1', '!', '1' },
	{ '2', '"', '2' },
	{ '3', 0x2116, '3' },
	{ '4', ';', '4' },
	{ '5', ':', '5' },
	{ '6', ',', '6' },
	{ '7', '.', '7' },
	{ '8', '(', '8' },
	{ '9', ')', '9' },
	{ '0', '?', '0' },

	{ 'Q', 0x409, 0x459 },
	{ 'W', 0x40a, 0x45a },
	{ 'E', 0x415, 0x435 },
	{ 'R', 0x420, 0x440 },
	{ 'T', 0x422, 0x442 },
	{ 'Y', 0x405, 0x455 },
	{ 'U', 0x423, 0x443 },
	{ 'I', 0x418, 0x438 },
	{ 'O', 0x41e, 0x43e },
	{ 'P', 0x41f, 0x43f },

	{ 'A', 0x410, 0x430 },
	{ 'S', 0x421, 0x441 },
	{ 'D', 0x414, 0x434 },
	{ 'F', 0x424, 0x444 },
	{ 'G', 0x413, 0x433 },
	{ 'H', 0x425, 0x445 },
	{ 'J', 0x408, 0x458 },
	{ 'K', 0x41a, 0x43a },
	{ 'L', 0x41b, 0x43b },

	{ 'Z', 0x417, 0x437 },
	{ 'X', 0x40f, 0x45f },
	{ 'C', 0x426, 0x446 },
	{ 'V', 0x412, 0x432 },
	{ 'B', 0x411, 0x431 },
	{ 'N', 0x41d, 0x43d },
	{ 'M', 0x41c, 0x43c },

	{ 0x1049, 0x428, 0x448 },
	{ 0x1044, 0x403, 0x453 },
	{ '-', 0x416, 0x436 },
	{ ',', 0x427, 0x447 },
	{ '.', 0x40c, 0x45c },
	{ '/', 0x427, 0x427 },
	{ '?', 0x40c, 0x40c },
	{0,0,0},

//	{ '@', 0x42d, 0x44d },
//	{ '<', 0x416, 0x436 },
//	{ '>', 0x401, 0x451 },
//	{ '{', 0x416, 0x416 },
//	{ '}', 0x401, 0x401 },
    },
//belorussian
    {
	{ '1', '!', '1' },
	{ '2', '"', '2' },
	{ '3', 0x2116, '3' },
	{ '4', ';', '4' },
	{ '5', ':', '5' },
	{ '6', ',', '6' },
	{ '7', '.', '7' },
	{ '8', '(', '8' },
	{ '9', ')', '9' },
	{ '0', '?', '0' },

	{ 'Q', 0x419, 0x439 },
	{ 'W', 0x426, 0x446 },
	{ 'E', 0x423, 0x443 },
	{ 'R', 0x41a, 0x43a },
	{ 'T', 0x415, 0x435 },
	{ 'Y', 0x41d, 0x43d },
	{ 'U', 0x413, 0x433 },
	{ 'I', 0x428, 0x448 },
	{ 'O', 0x40e, 0x45e },
	{ 'P', 0x417, 0x437 },
	
	{ 'A', 0x424, 0x444 },
	{ 'S', 0x42b, 0x44b },
	{ 'D', 0x412, 0x432 },
	{ 'F', 0x410, 0x430 },
	{ 'G', 0x41f, 0x43f },
	{ 'H', 0x420, 0x440 },
	{ 'J', 0x41e, 0x43e },
	{ 'K', 0x41b, 0x43b },
	{ 'L', 0x414, 0x434 },
	
	{ 'Z', 0x42f, 0x44f },
	{ 'X', 0x427, 0x447 },
	{ 'C', 0x421, 0x441 },
	{ 'V', 0x41c, 0x43c },
	{ 'B', 0x406, 0x456 },
	{ 'N', 0x422, 0x442 },
	{ 'M', 0x42c, 0x44c },

	{ 0x1049, 0x425, 0x445 },
	{ 0x1044, 0x42a, 0x44a },
	{ '-', 0x42d, 0x44d },
	{ ',', 0x411, 0x431 },
	{ '.', 0x42e, 0x44e },
	{ '/', 0x411, 0x411 },
	{ '?', 0x42e, 0x42e },

//	{ '@', 0x42d, 0x44d },
//	{ '<', 0x416, 0x436 },
//	{ '>', 0x401, 0x451 },
//	{ '{', 0x416, 0x416 },
//	{ '}', 0x401, 0x401 },

	{0,0,0},
    },
//bolgaria
    {
	{ '1', '!', '1' },
	{ '2', '"', '2' },
	{ '3', 0x2116, '3' },
	{ '4', ';', '4' },
	{ '5', ':', '5' },
	{ '6', ',', '6' },
	{ '7', '.', '7' },
	{ '8', '(', '8' },
	{ '9', ')', '9' },
	{ '0', '?', '0' },

	{ 'Q', 0x44b, ',' },
	{ 'W', 0x423, 0x443 },
	{ 'E', 0x415, 0x435 },
	{ 'R', 0x418, 0x438 },
	{ 'T', 0x428, 0x448 },
	{ 'Y', 0x429, 0x449 },
	{ 'U', 0x41a, 0x43a },
	{ 'I', 0x421, 0x441 },
	{ 'O', 0x414, 0x434 },
	{ 'P', 0x417, 0x437 },

	{ 'A', 0x42c, 0x44c },
	{ 'S', 0x42f, 0x44f },
	{ 'D', 0x410, 0x430 },
	{ 'F', 0x41e, 0x43e },
	{ 'G', 0x416, 0x436 },
	{ 'H', 0x413, 0x433 },
	{ 'J', 0x422, 0x442 },
	{ 'K', 0x41d, 0x43d },
	{ 'L', 0x412, 0x432 },

	{ 'Z', 0x42e, 0x44e },
	{ 'X', 0x419, 0x439 },
	{ 'C', 0x42a, 0x44a },
	{ 'V', 0x42d, 0x44d },
	{ 'B', 0x424, 0x444 },
	{ 'N', 0x425, 0x445 },
	{ 'M', 0x41f, 0x43f },

	{ 0x1049, 0x426, 0x446 },
	{ 0x1044, 0xa7, ';' },
	{ '-', 0x420, 0x440 },
	{ ',', 0x41b, 0x43b },
	{ '.', 0x411, 0x431 },
	{ '/', 0x41b, 0x41b },
	{ '?', 0x411, 0x411 },

//	{ '@', 0x42d, 0x44d },
//	{ '<', 0x416, 0x436 },
//	{ '>', 0x401, 0x451 },
//	{ '{', 0x416, 0x416 },
//	{ '}', 0x401, 0x401 },

	{0,0,0},
    },
//srbia
    {
	{ '1', '!', '1' },
	{ '2', '"', '2' },
	{ '3', 0x2116, '3' },
	{ '4', ';', '4' },
	{ '5', ':', '5' },
	{ '6', ',', '6' },
	{ '7', '.', '7' },
	{ '8', '(', '8' },
	{ '9', ')', '9' },
	{ '0', '?', '0' },

	{ 'Q', 0x409, 0x459 },
	{ 'W', 0x40a, 0x45a },
	{ 'E', 0x415, 0x435 },
	{ 'R', 0x420, 0x440 },
	{ 'T', 0x422, 0x442 },
	{ 'Y', 0x417, 0x437 },
	{ 'U', 0x423, 0x443 },
	{ 'I', 0x418, 0x438 },
	{ 'O', 0x41e, 0x43e },
	{ 'P', 0x41f, 0x43f },

	{ 'A', 0x410, 0x430 },
	{ 'S', 0x421, 0x441 },
	{ 'D', 0x414, 0x434 },
	{ 'F', 0x424, 0x444 },
	{ 'G', 0x413, 0x433 },
	{ 'H', 0x425, 0x445 },
	{ 'J', 0x408, 0x458 },
	{ 'K', 0x41a, 0x43a },
	{ 'L', 0x41b, 0x43b },

	{ 'Z', 0x405, 0x455 },
	{ 'X', 0x40f, 0x45f },
	{ 'C', 0x426, 0x446 },
	{ 'V', 0x412, 0x432 },
	{ 'B', 0x411, 0x431 },
	{ 'N', 0x41d, 0x43d },
	{ 'M', 0x41c, 0x43c },

	{ 0x1049, 0x428, 0x448 },
	{ 0x1044, 0x402, 0x452 },
	{ '-', 0x416, 0x436 },
	{ ',', 0x427, 0x447 },
	{ '.', 0x40b, 0x45b },
	{ '/', 0x427, 0x427 },
	{ '?', 0x40b, 0x40b },
	{0,0,0},

//	{ '@', 0x42d, 0x44d },
//	{ '<', 0x416, 0x436 },
//	{ '>', 0x401, 0x451 },
//	{ '{', 0x416, 0x416 },
//	{ '}', 0x401, 0x401 },
    },
//ukraina
    {
	{ '1', '!', '1' },
	{ '2', '"', '2' },
	{ '3', 0x2116, '3' },
	{ '4', ';', '4' },
	{ '5', ':', '5' },
	{ '6', ',', '6' },
	{ '7', '.', '7' },
	{ '8', '(', '8' },
	{ '9', ')', '9' },
	{ '0', '?', '0' },

	{ 'Q', 0x419, 0x439 },
	{ 'W', 0x426, 0x446 },
	{ 'E', 0x423, 0x443 },
	{ 'R', 0x41a, 0x43a },
	{ 'T', 0x415, 0x435 },
	{ 'Y', 0x41d, 0x43d },
	{ 'U', 0x413, 0x433 },
	{ 'I', 0x428, 0x448 },
	{ 'O', 0x429, 0x449 },
	{ 'P', 0x417, 0x437 },
	
	{ 'A', 0x424, 0x444 },
	{ 'S', 0x406, 0x456 },
	{ 'D', 0x412, 0x432 },
	{ 'F', 0x410, 0x430 },
	{ 'G', 0x41f, 0x43f },
	{ 'H', 0x420, 0x440 },
	{ 'J', 0x41e, 0x43e },
	{ 'K', 0x41b, 0x43b },
	{ 'L', 0x414, 0x434 },
	
	{ 'Z', 0x42f, 0x44f },
	{ 'X', 0x427, 0x447 },
	{ 'C', 0x421, 0x441 },
	{ 'V', 0x41c, 0x43c },
	{ 'B', 0x418, 0x438 },
	{ 'N', 0x422, 0x442 },
	{ 'M', 0x42c, 0x44c },

	{ 0x1049, 0x425, 0x445 },
	{ 0x1044, 0x407, 0x457 },
	{ '-', 0x404, 0x454 },
	{ ',', 0x411, 0x431 },
	{ '.', 0x42e, 0x44e },
	{ '/', 0x411, 0x411 },
	{ '?', 0x42e, 0x42e },

//	{ '@', 0x42d, 0x44d },
//	{ '<', 0x416, 0x436 },
//	{ '>', 0x401, 0x451 },
//	{ '{', 0x416, 0x416 },
//	{ '}', 0x401, 0x401 },

	{0,0,0},
    },
};
#elif (SLA300 == 1)
kbdecode hkeymap [][1] = {
    {
	{ 0, 0, 0},
    },
    {
	{ 0, 0, 0},
    },
    {
	{ 0, 0, 0},
    },
    {
	{ 0, 0, 0},
    },
    {
	{ 0, 0, 0},
    },
    {
	{ 0, 0, 0},
    },
    {
	{ 0, 0, 0},	
    }
};
#else
kbdecode hkeymap [][1] = { 
    {
	{ 0, 0, 0},
    },
    {
	{ 0, 0, 0},
    },
    {
	{ 0, 0, 0},
    },
    {
	{ 0, 0, 0},
    },
    {
	{ 0, 0, 0},
    },
    {
	{ 0, 0, 0},
    },
    {
	{ 0, 0, 0},	
    }
};
#endif


typedef struct _fnkbdecode{
    int	keycode;
    ushort unicode;
    ushort bunicode;
} fnkbdecode;

#if (SLC700 == 1)
fnkbdecode hkeymap_fn[][26] = {
#elif (SLA300 == 1)
fnkbdecode hkeymap_fn[][1] = {
#else
fnkbdecode hkeymap_fn[][11] = {
#endif
//russia
    {
#if (SLC700 == 1)
	{ '@', 0x42d, 0x44d },
	{ '<', 0x416, 0x436 },
	{ '>', 0x401, 0x451 },

	{ 0x2014, 0x419, 0x439 }, //q
	{ 0x005e, 0x426, 0x446 }, //w
	{ 0x003d, 0x401, 0x451 }, //e
	{ 0x002b, 0x41a, 0x43a }, //r
	{ 0x005b, 0x415, 0x435 }, //t
	{ 0x005d, 0x41d, 0x43d }, //y
	{ 0x00a2, 0x413, 0x433 }, //u
	{ 0x00a3, 0x428, 0x448 }, //i
	{ 0x2015, 0x429, 0x449 }, //o
	{ 0x2016, 0x417, 0x437 }, //p
	
	{ 0x2017, 0x424, 0x444 }, //a
	{ 0x2018, 0x42b, 0x44b }, //s
	{ 0x00a5, 0x412, 0x432 }, //d
	{ 0x005c, 0x410, 0x430 }, //f
	{ 0x003b, 0x41f, 0x43f }, //g
	{ 0x003a, 0x420, 0x440 }, //h
	{ 0x002a, 0x41e, 0x43e }, //j
	{ 0x2022, 0x41b, 0x43b }, //k
	{ 0x007c, 0x414, 0x434 }, //l
	
//	{ 0x005a, 0, 0 }, //z
//	{ 0x0058, 0, 0 }, //x
//	{ 0x0043, 0, 0 }, //c
//	{ 0x0056, 0, 0 }, //v
	{ 0x005f, 0x418, 0x438 }, //b
	{ 0x2019, 0x422, 0x442 }, //n
	{ 0x201a, 0x42c, 0x44c }, //m

#elif (SLA300 == 1)
#else
	{ '@', 0x416 },
	{ '#', 0x436 },
	{ '$', 0x429 },
	{ '%', 0x449 },
	{ '_', 0x42d },
	{ '&', 0x44d },
	{ '+', 0x42e },
	{ '=', 0x44e },
	{ '~', 0x44c },
	{0,0},
#endif
	{0,0,0}
    },
//makedonia    
    {
#if (SLC700 == 1)
	{ 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 0 },

	{ 0x2014, 0, 0 }, //q
	{ 0x005e, 0, 0 }, //w
	{ 0x003d, 0, 0 }, //e
	{ 0x002b, 0, 0 }, //r
	{ 0x005b, 0, 0 }, //t
	{ 0x005d, 0, 0 }, //y
	{ 0x00a2, 0, 0 }, //u
	{ 0x00a3, 0, 0 }, //i
	{ 0x2015, 0, 0 }, //o
	{ 0x2016, 0, 0 }, //p
	
	{ 0x2017, 0, 0 }, //a
	{ 0x2018, 0, 0 }, //s
	{ 0x00a5, 0, 0 }, //d
	{ 0x005c, 0, 0 }, //f
	{ 0x003b, 0, 0 }, //g
	{ 0x003a, 0, 0 }, //h
	{ 0x002a, 0, 0 }, //j
	{ 0x2022, 0, 0 }, //k
	{ 0x007c, 0, 0 }, //l
	
//	{ 0x005a, 0, 0 }, //z
//	{ 0x0058, 0, 0 }, //x
//	{ 0x0043, 0, 0 }, //c
//	{ 0x0056, 0, 0 }, //v
	{ 0x005f, 0, 0 }, //b
	{ 0x2019, 0, 0 }, //n
	{ 0x201a, 0, 0 }, //m

#elif (SLA300 == 1)
#else
	{ '@', 0x428 },
	{ '#', 0x448 },
	{ '$', 0x403 },
	{ '%', 0x453 },
	{ '_', 0x416 },
	{ '&', 0x436 },
	{ '+', 0x427 },
	{ '=', 0x447 },
	{ '<', 0x40c },
	{ '>', 0x45c },
#endif
	{0,0,0}
    },
//belorussia
    {
#if (SLC700 == 1)
	{ '@', 0x42d, 0x44d },
	{ '<', 0x416, 0x436 },
	{ '>', 0x401, 0x451 },

	{ 0x2014, 0x419, 0x439 }, //q
	{ 0x005e, 0x426, 0x446 }, //w
	{ 0x003d, 0x401, 0x451 }, //e
	{ 0x002b, 0x41a, 0x43a }, //r
	{ 0x005b, 0x415, 0x435 }, //t
	{ 0x005d, 0x41d, 0x43d }, //y
	{ 0x00a2, 0x413, 0x433 }, //u
	{ 0x00a3, 0x428, 0x448 }, //i
	{ 0x2015, 0x40e, 0x45e }, //o
	{ 0x2016, 0x417, 0x437 }, //p
	
	{ 0x2017, 0x424, 0x444 }, //a
	{ 0x2018, 0x42b, 0x44b }, //s
	{ 0x00a5, 0x412, 0x432 }, //d
	{ 0x005c, 0x410, 0x430 }, //f
	{ 0x003b, 0x41f, 0x43f }, //g
	{ 0x003a, 0x420, 0x440 }, //h
	{ 0x002a, 0x41e, 0x43e }, //j
	{ 0x2022, 0x41b, 0x43b }, //k
	{ 0x007c, 0x414, 0x434 }, //l
	
//	{ 0x005a, 0, 0 }, //z
//	{ 0x0058, 0, 0 }, //x
//	{ 0x0043, 0, 0 }, //c
//	{ 0x0056, 0, 0 }, //v
	{ 0x005f, 0x406, 0x456 }, //b
	{ 0x2019, 0x422, 0x442 }, //n
	{ 0x201a, 0x42c, 0x44c }, //m

#elif (SLA300 == 1)
#else
	{ '@', 0x416 },
	{ '#', 0x436 },
	{ '$', 0x40e },
	{ '%', 0x45e },
	{ '_', 0x42d },
	{ '&', 0x44d },
	{ '+', 0x42e },
	{ '=', 0x44e },
	{ '~', 0x44c },
	{0,0},
#endif
	{0,0,0},
    },
//bolgaria
    {
#if (SLC700 == 1)
	{ '@', 0x42d, 0x44d },
	{ '<', 0x416, 0x436 },
	{ '>', 0x401, 0x451 },

	{ 0x2014, 0, 0 }, //q
	{ 0x005e, 0, 0 }, //w
	{ 0x003d, 0, 0 }, //e
	{ 0x002b, 0, 0 }, //r
	{ 0x005b, 0, 0 }, //t
	{ 0x005d, 0, 0 }, //y
	{ 0x00a2, 0, 0 }, //u
	{ 0x00a3, 0, 0 }, //i
	{ 0x2015, 0, 0 }, //o
	{ 0x2016, 0, 0 }, //p
	
	{ 0x2017, 0, 0 }, //a
	{ 0x2018, 0, 0 }, //s
	{ 0x00a5, 0, 0 }, //d
	{ 0x005c, 0, 0 }, //f
	{ 0x003b, 0, 0 }, //g
	{ 0x003a, 0, 0 }, //h
	{ 0x002a, 0, 0 }, //j
	{ 0x2022, 0, 0 }, //k
	{ 0x007c, 0, 0 }, //l
	
//	{ 0x005a, 0, 0 }, //z
//	{ 0x0058, 0, 0 }, //x
//	{ 0x0043, 0, 0 }, //c
//	{ 0x0056, 0, 0 }, //v
	{ 0x005f, 0, 0 }, //b
	{ 0x2019, 0, 0 }, //n
	{ 0x201a, 0, 0 }, //m


#elif (SLA300 == 1)
#else
	{ '@', 0x416 },
	{ '#', 0x436 },
	{ '$', 0x429 },
	{ '%', 0x449 },
	{ '_', 0x42d },
	{ '&', 0x44d },
	{ '+', 0x42e },
	{ '=', 0x44e },
	{ '~', 0x44c },
	{0,0},
#endif
	{0,0,0}
    },
//srbia
    {
#if (SLC700 == 1)
	{ 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 0 },

	{ 0x2014, 0, 0 }, //q
	{ 0x005e, 0, 0 }, //w
	{ 0x003d, 0, 0 }, //e
	{ 0x002b, 0, 0 }, //r
	{ 0x005b, 0, 0 }, //t
	{ 0x005d, 0, 0 }, //y
	{ 0x00a2, 0, 0 }, //u
	{ 0x00a3, 0, 0 }, //i
	{ 0x2015, 0, 0 }, //o
	{ 0x2016, 0, 0 }, //p
	
	{ 0x2017, 0, 0 }, //a
	{ 0x2018, 0, 0 }, //s
	{ 0x00a5, 0, 0 }, //d
	{ 0x005c, 0, 0 }, //f
	{ 0x003b, 0, 0 }, //g
	{ 0x003a, 0, 0 }, //h
	{ 0x002a, 0, 0 }, //j
	{ 0x2022, 0, 0 }, //k
	{ 0x007c, 0, 0 }, //l
	
//	{ 0x005a, 0, 0 }, //z
//	{ 0x0058, 0, 0 }, //x
//	{ 0x0043, 0, 0 }, //c
//	{ 0x0056, 0, 0 }, //v
	{ 0x005f, 0, 0 }, //b
	{ 0x2019, 0, 0 }, //n
	{ 0x201a, 0, 0 }, //m


#elif (SLA300 == 1)
#else
	{ '@', 0x428 },
	{ '#', 0x448 },
	{ '$', 0x402 },
	{ '%', 0x452 },
	{ '_', 0x416 },
	{ '&', 0x436 },
	{ '+', 0x427 },
	{ '=', 0x447 },
	{ '<', 0x40b },
	{ '>', 0x45b },
#endif
	{0,0,0}
    },
//ukraina
    {
#if (SLC700 == 1)
	{ '@', 0x42d, 0x44d },
	{ '<', 0x416, 0x436 },
	{ '>', 0x401, 0x451 },

	{ 0x2014, 0x419, 0x439 }, //q
	{ 0x005e, 0x426, 0x446 }, //w
	{ 0x003d, 0x401, 0x451 }, //e
	{ 0x002b, 0x41a, 0x43a }, //r
	{ 0x005b, 0x415, 0x435 }, //t
	{ 0x005d, 0x41d, 0x43d }, //y
	{ 0x00a2, 0x413, 0x433 }, //u
	{ 0x00a3, 0x428, 0x448 }, //i
	{ 0x2015, 0x429, 0x449 }, //o
	{ 0x2016, 0x417, 0x437 }, //p
	
	{ 0x2017, 0x424, 0x444 }, //a
	{ 0x2018, 0x406, 0x456 }, //s
	{ 0x00a5, 0x412, 0x432 }, //d
	{ 0x005c, 0x410, 0x430 }, //f
	{ 0x003b, 0x41f, 0x43f }, //g
	{ 0x003a, 0x420, 0x440 }, //h
	{ 0x002a, 0x41e, 0x43e }, //j
	{ 0x2022, 0x41b, 0x43b }, //k
	{ 0x007c, 0x414, 0x434 }, //l
	
//	{ 0x005a, 0, 0 }, //z
//	{ 0x0058, 0, 0 }, //x
//	{ 0x0043, 0, 0 }, //c
//	{ 0x0056, 0, 0 }, //v
	{ 0x005f, 0x418, 0x438 }, //b
	{ 0x2019, 0x422, 0x442 }, //n
	{ 0x201a, 0x42c, 0x44c }, //m

#elif (SLA300 == 1)
#else
	{ '@', 0x416 },
	{ '#', 0x436 },
	{ '$', 0x429 },
	{ '%', 0x449 },
	{ '_', 0x404 },
	{ '&', 0x454 },
	{ '+', 0x42e },
	{ '=', 0x44e },
	{ '~', 0x44c },
	{0,0},
#endif
	{0,0,0}
    }
};
