if(ESP_PLATFORM)
    file(GLOB SOURCES *.c 
                    Publisher/*.c 
                    Subscriber/*.c 
                    DataCenter/*.c )

    set(PULISH_SUBSCRIBE_INCLUDE_DIRS . 
                                    Publisher 
                                    Subscriber 
                                    DataCenter )

    # Add touch driver to compilation only if it is selected in menuconfig
    idf_component_register(SRCS ${SOURCES}
        INCLUDE_DIRS ${PULISH_SUBSCRIBE_INCLUDE_DIRS})

    target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_LVGL_H_INCLUDE_SIMPLE")

else()
    message(FATAL_ERROR "LVGL ESP32 drivers: ESP_PLATFORM is not defined. Try reinstalling ESP-IDF.")
endif()
