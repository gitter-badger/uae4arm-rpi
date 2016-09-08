/*
 * UAE - The Un*x Amiga Emulator
 *
 * Target specific stuff, Pandora version
 *
 * Copyright 1997 Bernd Schmidt
 */

#include <SDL.h>

#ifdef _WIN32_WCE
#define TARGET_NAME "WinCE"
#define TARGET_NO_AUTOCONF
#define TARGET_NO_ZFILE
#define DONT_PARSE_CMDLINE
#else
#define TARGET_NAME "pandora"
#endif
#define TARGET_PROVIDES_DEFAULT_PREFS
#define TARGET_NO_DITHER

#define NO_MAIN_IN_MAIN_C

#define OPTIONSFILENAME _T("default.uae")

extern int emulating;

extern int z3_start_adr;
extern int rtg_start_adr;

extern int currVSyncRate;

void run_gui(void);
void InGameMessage(const char *msg);
void wait_for_vsync(void);

void saveAdfDir(void);
bool SetVSyncRate(int hz);
void setCpuSpeed(void);
void resetCpuSpeed(void);
void update_display(struct uae_prefs *);
void black_screen_now(void);
void graphics_subshutdown (void);

void pandora_stop_sound(void);

void keyboard_settrans (void);
int translate_pandora_keys(int symbol, int *modifier);
void SimulateMouseOrJoy(int code, int keypressed);

#define REMAP_MOUSEBUTTON_LEFT    -1
#define REMAP_MOUSEBUTTON_RIGHT   -2
#define REMAP_JOYBUTTON_ONE       -3
#define REMAP_JOYBUTTON_TWO       -4
#define REMAP_JOY_UP              -5
#define REMAP_JOY_DOWN            -6
#define REMAP_JOY_LEFT            -7
#define REMAP_JOY_RIGHT           -8
#define REMAP_CD32_GREEN          -9
#define REMAP_CD32_YELLOW         -10
#define REMAP_CD32_PLAY           -11
#define REMAP_CD32_FFW            -12
#define REMAP_CD32_RWD            -13

void reinit_amiga(void);
int count_HDs(struct uae_prefs *p);
extern void gui_force_rtarea_hdchange(void);
extern bool hardfile_testrdb(const char *filename);

#ifdef __cplusplus
extern "C" {
#endif
void trace_begin (void);
void trace_end (void);
#ifdef __cplusplus
}
#endif


static __inline__ size_t uae_tcslcpy(char *dst, const char *src, size_t size)
{
    if (size == 0)
    {
        return 0;
    }
	size_t src_len = strlen(src);
    size_t cpy_len = src_len;
    if (cpy_len >= size)
    {
        cpy_len = size - 1;
    }
	memcpy(dst, src, cpy_len * sizeof(char));
    dst[cpy_len] = ('\0');
    return src_len;
}

static __inline__ size_t uae_strlcpy(char *dst, const char *src, size_t size)
{
    if (size == 0)
    {
        return 0;
    }
    size_t src_len = strlen(src);
    size_t cpy_len = src_len;
    if (cpy_len >= size)
    {
        cpy_len = size - 1;
    }
    memcpy(dst, src, cpy_len);
    dst[cpy_len] = '\0';
    return src_len;
}

static __inline__ int max(int x, int y)
{
    return x > y ? x : y;
}
