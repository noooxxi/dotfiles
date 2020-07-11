//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"", "cat /tmp/recordingicon 2>/dev/null",	0,	9},
	/* {"",	"~/dwmblocks/statusbar/music",		0,	11},*/
	/* {"",	"~/dwmblocks/statusbar/pacpackages",	0,	8}, */
	/* {"",	"~/dwmblocks/statusbar/news",		0,	6}, */
	/* {"",	"~/dwmblocks/statusbar/crypto",		0,	13}, */
	/* {"",	"price btc Bitcoin 💰",			0,	21}, */
	/* {"",	"~/dwmblocks/statusbar/torrent",	20,	7}, */
	/* {"",	"~/dwmblocks/statusbar/memory",		10,	14}, */
	/* {"",	"~/dwmblocks/statusbar/cpu",		10,	18}, */
	/* {"",	"~/dwmblocks/statusbar/moonphase",	18000,	17}, */
	{"",	"~/dwmblocks/statusbar/weather",	18000,	5},
	/* {"",	"~/dwmblocks/statusbar/mailbox",	180,	12}, */
	/* {"",	"~/dwmblocks/statusbar/nettraf",	1,	16}, */
	{"",	"~/dwmblocks/statusbar/brightness",	0,	22},
	{"",	"~/dwmblocks/statusbar/volume",		0,	10},
	{"",	"~/dwmblocks/statusbar/battery",	5,	3},
	{"",	"~/dwmblocks/statusbar/clock",		60,	1},
	/* {"",	"~/dwmblocks/statusbar/internet",	5,	4},  */
	/* {"",	"~/dwmblocks/statusbar/help-icon",	0,	15}, */
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char *delim = " ";

// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid dwmblocks & }
