COMPONENT_SRCDIRS := . src
COMPONENT_ADD_INCLUDEDIRS := . src

# LVGL is supposed to be used as a ESP-IDF component
# -> lvlg is already in the include path
# -> we use simple include
CFLAGS += -DLV_LVGL_H_INCLUDE_SIMPLE
