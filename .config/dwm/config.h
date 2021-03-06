/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;         /* border pixel of windows */
static const unsigned int snap      = 32;        /* snap pixel */
static const unsigned int gappih    = 29;        /* horizontal inner gap between windows */
static const unsigned int gappiv    = 29;        /* vertical inner gap between windows */
static const unsigned int gappoh    = 29;        /* horizontal outer gap between windows and screen edge */
static const unsigned int gappov    = 29;        /* vertical outer gap between windows and screen edge */
static const int swallowfloating    = 0;         /* 1 means swallow floating windows by default */
static const int smartgaps          = 0;         /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;         /* 0 means no bar */
static const int topbar             = 1;         /* 0 means bottom bar */
static const int usealtbar          = 1;         /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const char *fonts[]          = { "monospace:size=10", "JoyPixels:pixelsize=10:antialias=true:autohint=true"  };
static char dmenufont[]             = "monospace:size=10";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#691654";
static char selbgcolor[]            = "#691654";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"kitty", "120x34", NULL };
const char *spcmd2[] = {"kitty", "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spranger",    spcmd2},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class    instance      title       	 tags mask    isfloating   isterminal  noswallow  monitor */
	{ "Gimp",     NULL,       NULL,       	    1 << 8,       0,           0,         0,        -1 },
	{ "St",       NULL,       NULL,       	    0,            0,           1,         0,        -1 },
	{ NULL,       NULL,       "Event Tester",   0,            0,           0,         1,        -1 },
	{ NULL,      "spterm",    NULL,       	    SPTAG(0),     1,           1,         0,        -1 },
	{ NULL,      "spcalc",    NULL,       	    SPTAG(1),     1,           1,         0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
 	{ "[]=",	tile },			/* Default: Master on left, slaves on right */
	{ "TTT",	bstack },		/* Master on top, slaves on bottom */

	{ "[@]",	spiral },		/* Fibonacci spiral */
	{ "[\\]",	dwindle },		/* Decreasing in size right and leftward */

	{ "H[]",	deck },			/* Master on left, slaves in monocle-like mode on right */
 	{ "[M]",	monocle },		/* All windows on top of eachother */

	{ "|M|",	centeredmaster },		/* Master in middle, slaves on sides */
	{ ">M>",	centeredfloatingmaster },	/* Same but master floats */

	{ "><>",	NULL },			/* no layout function means floating behavior */
	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,	          	{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     	{.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            	{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,		KEY,      spawn,		SHCMD("polybar-msg hook tags 1") }, \
	{ MODKEY,			KEY,      spawn,		SHCMD("polybar-msg hook tags 1") },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \
	{ MOD,  XK_v,   ACTION##stack,  {.i = 0 } }, \
	/* { MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \ */
	/* { MOD, XK_a,     ACTION##stack, {.i = 1 } }, \ */
	/* { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \ */
	/* { MOD, XK_x,     ACTION##stack, {.i = -1 } }, */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *browser[]  = { "firefox", NULL };

#include <X11/XF86keysym.h>
#include "shiftview.c"
static Key keys[] = {
	/* modifier                     key             function        argument */
	STACKKEYS(MODKEY,                          	focus)
	STACKKEYS(MODKEY|ShiftMask,                	push)
	TAGKEYS(			XK_1,		0)
	TAGKEYS(			XK_2,		1)
	TAGKEYS(			XK_3,		2)
	TAGKEYS(			XK_4,		3)
	TAGKEYS(			XK_5,		4)
	TAGKEYS(			XK_6,		5)
	TAGKEYS(			XK_7,		6)
	TAGKEYS(			XK_8,		7)
	TAGKEYS(			XK_9,		8)
	{ MODKEY,			XK_0,		view,		{.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,		tag,		{.ui = ~0 } },
	{ MODKEY,			XK_0,		view,		{.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,		tag,		{.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,		spawn,		SHCMD("polybar-msg hook tags 1") },
	{ MODKEY,			XK_0,		spawn,		SHCMD("polybar-msg hook tags 1") },
	{ MODKEY,			XK_minus,	spawn,		SHCMD("pamixer --allow-boost -d 5") },
	{ MODKEY|ShiftMask,		XK_minus,	spawn,		SHCMD("pamixer --allow-boost -d 15") },
	{ MODKEY,			XK_plus,	spawn,		SHCMD("pamixer --allow-boost -i 5") },
	{ MODKEY|ShiftMask,		XK_plus,	spawn,		SHCMD("pamixer --allow-boost -i 15") },
	{ MODKEY,			XK_BackSpace,	spawn,		SHCMD("rofi -show run") },
	{ MODKEY|ShiftMask,		XK_BackSpace,	quit,		{0} },
	{ MODKEY,			XK_Tab,		view,		{0} },
	{ MODKEY,			XK_Tab,		spawn,		SHCMD("polybar-msg hook tags 1") },
	/* { MODKEY|ShiftMask,		XK_Tab,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_q,		killclient,	{0} },
	/* { MODKEY|ShiftMask,		XK_q,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_w,           spawn,          {.v = browser } },
	{ MODKEY|ShiftMask,		XK_w,		spawn,		SHCMD("kitty -e sudo nmtui") },
	{ MODKEY,			XK_e,		spawn,		SHCMD("kitty -e ranger") },
	{ MODKEY|ShiftMask,		XK_e,		spawn,		SHCMD("kitty -e neomutt") },
	{ MODKEY,			XK_r,		spawn,		SHCMD("kitty -e newsboat") },
	{ MODKEY|ShiftMask,		XK_r,		spawn,		SHCMD("kitty -e transmission-remote -l") },
	{ MODKEY,			XK_t,		setlayout,	{.v = &layouts[0]} }, /* tile */
	{ MODKEY|ShiftMask,		XK_t,		setlayout,	{.v = &layouts[1]} }, /* bstack */
	{ MODKEY,			XK_y,		setlayout,	{.v = &layouts[2]} }, /* spiral */
	{ MODKEY|ShiftMask,		XK_y,		setlayout,	{.v = &layouts[3]} }, /* dwindle */
	{ MODKEY,			XK_u,		setlayout,	{.v = &layouts[4]} }, /* deck */
	{ MODKEY|ShiftMask,		XK_u,		setlayout,	{.v = &layouts[5]} }, /* monocle */
	{ MODKEY,			XK_i,		setlayout,	{.v = &layouts[6]} }, /* centeredmaster */
	{ MODKEY|ShiftMask,		XK_i,		setlayout,	{.v = &layouts[7]} }, /* centeredfloatingmaster */
	{ MODKEY,			XK_t,		spawn,		SHCMD("polybar-msg hook layout 1") },
	{ MODKEY|ShiftMask,		XK_t,		spawn,		SHCMD("polybar-msg hook layout 1") },
	{ MODKEY,			XK_y,		spawn,		SHCMD("polybar-msg hook layout 1") },
	{ MODKEY|ShiftMask,		XK_y,		spawn,		SHCMD("polybar-msg hook layout 1") },
	{ MODKEY,			XK_u,		spawn,		SHCMD("polybar-msg hook layout 1") },
	{ MODKEY|ShiftMask,		XK_u,		spawn,		SHCMD("polybar-msg hook layout 1") },
	{ MODKEY,			XK_i,		spawn,		SHCMD("polybar-msg hook layout 1") },
	{ MODKEY|ShiftMask,		XK_i,		spawn,		SHCMD("polybar-msg hook layout 1") },
	{ MODKEY,			XK_o,		incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_o,		incnmaster,     {.i = -1 } },
	{ MODKEY,			XK_p,		spawn,		SHCMD("mpc toggle") },
	{ MODKEY|ShiftMask,		XK_p,		spawn,		SHCMD("mpc pause ; pauseallmpv") },
	/* { MODKEY,			XK_å,		spawn,		SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_å,		spawn,		SHCMD("") }, */

	{ MODKEY,			XK_a,		togglegaps,	{0} },
	{ MODKEY|ShiftMask,		XK_a,		defaultgaps,	{0} },
	{ MODKEY,			XK_s,		togglesticky,	{0} },
	/* { MODKEY|ShiftMask,		XK_s,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_d,		spawn,		SHCMD("discord") },
	/* { MODKEY|ShiftMask,		XK_d,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_f,		togglefullscr,	{0} },
	{ MODKEY|ShiftMask,		XK_f,		setlayout,	{.v = &layouts[8]} },
	{ MODKEY,			XK_g,		spawn,		SHCMD("kitty -e gotop") },
	{ MODKEY|ShiftMask,		XK_g,		spawn,		SHCMD("kitty -e htop") },
	{ MODKEY,			XK_h,		setmfact,	{.f = -0.05} },
	/* { MODKEY|ShiftMask,		XK_h,		spawn,		SHCMD("") }, */
	/* J is already bound in STACKEYS */
	{ MODKEY|ShiftMask,		XK_j,		tagmon,		{.i = -1 } },
	{ MODKEY|ControlMask,		XK_j,		focusmon,	{.i = -1 } },
	/* K is already bound in STACKEYS */
	{ MODKEY|ShiftMask,		XK_k,		tagmon,		{.i = +1 } },
	{ MODKEY|ControlMask,		XK_k,		focusmon,	{.i = +1 } },
	{ MODKEY,			XK_l,		setmfact,      	{.f = +0.05} },
	{ MODKEY|ShiftMask,		XK_l,		spawn,      	SHCMD("light-locker-command -l") },
	/* { MODKEY,			XK_ö,		spawn,		SHCMD("mpc seek -10") }, */
	/* { MODKEY|ShiftMask,		XK_ö,		spawn,		SHCMD("mpc seek -60") }, */
	/* { MODKEY,			XK_ä,		spawn,		SHCMD("mpc seek +10") }, */
	/* { MODKEY|ShiftMask,		XK_ä,		spawn,		SHCMD("mpc seek +60") }, */
	{ MODKEY,			XK_Return,	spawn,		{.v = termcmd } },
	{ MODKEY|ShiftMask,		XK_Return,	togglescratch,	{.ui = 0} },

	{ MODKEY,			XK_z,		incrgaps,	{.i = +3 } },
	/* { MODKEY|ShiftMask,		XK_z,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_x,		incrgaps,	{.i = -3 } },
	/* { MODKEY|ShiftMask,		XK_x,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_c,		spawn,		SHCMD("kitty -e weechat") }, 
	/* { MODKEY|ShiftMask,		XK_c,		spawn,		SHCMD("") }, */
	/* V is automatically bound above in STACKKEYS */
	{ MODKEY,			XK_b,		togglebar,	{0} },
	/* { MODKEY|ShiftMask,		XK_b,		spawn,		SHCMD("") },*/
	{ MODKEY,			XK_n,		spawn,		SHCMD("kitty -e sncli") },
	{ MODKEY|ShiftMask,		XK_n,		spawn,		SHCMD("kitty -e sncli create") },
	{ MODKEY,			XK_m,		spawn,		SHCMD("kitty -e ncmpcpp") },
	{ MODKEY|ShiftMask,		XK_m,		spawn,		SHCMD("kitty -e pulsemixer") },
	{ MODKEY,			XK_comma,	spawn,		SHCMD("mpc prev") },
	{ MODKEY|ShiftMask,		XK_comma,	spawn,		SHCMD("mpc seek 0%") },
	{ MODKEY,			XK_period,	spawn,		SHCMD("mpc next") },
	{ MODKEY|ShiftMask,		XK_period,	spawn,		SHCMD("mpc repeat") },

	{ MODKEY,			XK_Left,	spawn,		SHCMD("pamixer --allow-boost -d 5") },
	{ MODKEY|ShiftMask,		XK_Left,	spawn,		SHCMD("pamixer --allow-boost -d 15") },
	{ MODKEY,			XK_Right,	spawn,		SHCMD("pamixer --allow-boost -i 5") },
	{ MODKEY|ShiftMask,		XK_Right,	spawn,		SHCMD("pamixer --allow-boost -i 15") },
	/* { MODKEY,			XK_Up,		spawn,		SHCMD("xbacklight -inc 5; notify-send -t 1000 \"Brightness\" \"$(xbacklight -get)\"") },*/
	/* { MODKEY,			XK_Down,	spawn,		SHCMD("xbacklight -dec 5; notify-send -t 1000 \"Brightness\" \"$(xbacklight -get)\"") },*/
	{ MODKEY,			XK_Up,		spawn,		SHCMD("xbacklight -inc 5") },
	{ MODKEY|ShiftMask,		XK_Up,		spawn,		SHCMD("xbacklight -inc 15") },
	{ MODKEY,			XK_Down,	spawn,		SHCMD("xbacklight -dec 5") },
	{ MODKEY|ShiftMask,		XK_Down,	spawn,		SHCMD("xbacklight -dec 15") },

	{ MODKEY,			XK_Page_Up,	shiftview,	{ .i = -1 } },
	{ MODKEY|ShiftMask,		XK_Page_Up,	shifttag,	{ .i = -1 } },
	{ MODKEY,			XK_Page_Down,	shiftview,	{ .i = +1 } },
	{ MODKEY|ShiftMask,		XK_Page_Down,	shifttag,	{ .i = +1 } },
	{ MODKEY,			XK_Insert,	spawn,		SHCMD("notify-send \"📋 Clipboard contents:\" \"$(xclip -o -selection clipboard)\"") },

	{ MODKEY,			XK_F1,		spawn,		SHCMD("groff -mom /usr/local/share/dwm/larbs.mom -Tpdf | zathura -") },
	{ MODKEY,			XK_F2,		spawn,		SHCMD("tutorialvids") },
	{ MODKEY,			XK_F3,		spawn,		SHCMD("displayselect") },
	{ MODKEY,			XK_F4,		spawn,		SHCMD("kitty -e pulsemixer") },
	{ MODKEY,			XK_F5,		xrdb,		{.v = NULL } },
	{ MODKEY,			XK_F6,		spawn,		SHCMD("torwrap") },
	{ MODKEY,			XK_F7,		spawn,		SHCMD("td-toggle") },
	{ MODKEY,			XK_F8,		spawn,		SHCMD("mailsync") },
	{ MODKEY,			XK_F9,		spawn,		SHCMD("dmenumount") },
	{ MODKEY,			XK_F10,		spawn,		SHCMD("dmenuumount") },
	{ MODKEY,			XK_F11,		spawn,		SHCMD("mpv --no-cache --no-osc --no-input-default-bindings --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
	{ MODKEY,			XK_F12,		xrdb,		{.v = NULL } },
	{ MODKEY,			XK_space,	zoom,		{0} },
	{ MODKEY|ShiftMask,		XK_space,	togglefloating,	{0} },

	{ 0,				XK_Print,	spawn,		SHCMD("scrot") },
	{ ShiftMask,			XK_Print,	spawn,		SHCMD("maimpick") },
	/*{ MODKEY,			XK_Print,	spawn,		SHCMD("") },*/
	{ MODKEY|ShiftMask,		XK_Print,	spawn,		SHCMD("dmenurecord kill") },
	{ MODKEY,			XK_Delete,	spawn,		SHCMD("dmenurecord kill") },
	{ MODKEY|ShiftMask,		XK_Delete,	spawn,		SHCMD("killall xinit") },
	{ MODKEY,			XK_Scroll_Lock,	spawn,		SHCMD("killall screenkey || screenkey &") },

	{ 0, XF86XK_AudioMute,		spawn,		SHCMD("pamixer -t") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("pamixer --allow-boost -i 3") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("pamixer --allow-boost -d 3") },
	{ 0, XF86XK_AudioPrev,		spawn,		SHCMD("mpc prev") },
	{ 0, XF86XK_AudioNext,		spawn,		SHCMD("mpc next") },
	{ 0, XF86XK_AudioPause,		spawn,		SHCMD("mpc pause") },
	{ 0, XF86XK_AudioPlay,		spawn,		SHCMD("mpc toggle") },
	{ 0, XF86XK_AudioStop,		spawn,		SHCMD("mpc stop") },
	{ 0, XF86XK_AudioRewind,	spawn,		SHCMD("mpc seek -10") },
	{ 0, XF86XK_AudioForward,	spawn,		SHCMD("mpc seek +10") },
	{ 0, XF86XK_AudioMedia,		spawn,		SHCMD("kitty -e ncmpcpp") },
	{ 0, XF86XK_PowerOff,		spawn,		SHCMD("sysact") },
	{ 0, XF86XK_Calculator,		spawn,		SHCMD("kitty -e bc -l") },
	{ 0, XF86XK_Sleep,		spawn,		SHCMD("sudo -A zzz") },
	{ 0, XF86XK_WWW,		spawn,		SHCMD("$BROWSER") },
	{ 0, XF86XK_DOS,		spawn,		SHCMD("kitty") },
	{ 0, XF86XK_ScreenSaver,	spawn,		SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
	{ 0, XF86XK_TaskPane,		spawn,		SHCMD("kitty -e htop") },
	{ 0, XF86XK_Mail,		spawn,		SHCMD("kitty -e neomutt") },
	{ 0, XF86XK_MyComputer,		spawn,		SHCMD("kitty -e ranger /") },
	/* { 0, XF86XK_Battery,		spawn,		SHCMD("") }, */
	{ 0, XF86XK_Launch1,		spawn,		SHCMD("xset dpms force off") },
	{ 0, XF86XK_TouchpadToggle,	spawn,		SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOff,	spawn,		SHCMD("synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOn,		spawn,		SHCMD("synclient TouchpadOff=0") },
	{ 0, XF86XK_MonBrightnessUp,	spawn,		SHCMD("xbacklight -inc 15") },
	{ 0, XF86XK_MonBrightnessDown,	spawn,		SHCMD("xbacklight -dec 15") },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD("kitty -e vim ~/.local/src/dwmblocks/config.h") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        defaultgaps,	{0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,		MODKEY,		Button4,	incrgaps,	{.i = +1} },
	{ ClkClientWin,		MODKEY,		Button5,	incrgaps,	{.i = -1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,		0,		Button4,	shiftview,	{.i = -1} },
	{ ClkTagBar,		0,		Button5,	shiftview,	{.i = 1} },
	{ ClkRootWin,		0,		Button2,	togglebar,	{0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  spawn,               1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};
