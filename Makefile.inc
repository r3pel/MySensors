prefix=/usr/local
BINDIR=bin
BUILDDIR=build
GATEWAY_DIR=$(prefix)/bin
SOC=BCM2711

# Jouw aangepaste variabelen
GATEWAY_VARS=-DMY_DEBUG -DMY_GATEWAY_MQTT_CLIENT -DMY_GATEWAY_LINUX -DMY_RADIO_NRF24 \
             -DMY_CONTROLLER_URL_ADDRESS=\"127.0.0.1\" \
             -DMY_PORT=1883 \
             -DMY_MQTT_PUBLISH_TOPIC_PREFIX=\"mygateway1-out\" \
             -DMY_MQTT_SUBSCRIBE_TOPIC_PREFIX=\"mygateway1-in\" \
             -DMY_MQTT_CLIENT_ID=\"mysensors-1\" \
             -DMY_MQTT_USER=\"user\" \
             -DMY_MQTT_PASSWORD=\"passw\"

# Compiler instellingen (niet wijzigen voor Pi 4/5)
CFLAGS=-Ofast -g -Wall -Wextra -DLINUX_SPI_SPIDEV -DLINUX_ARCH_RASPBERRYPI $(GATEWAY_VARS)
CXXFLAGS=-Ofast -g -Wall -Wextra -DLINUX_SPI_SPIDEV -DLINUX_ARCH_RASPBERRYPI $(GATEWAY_VARS)
CPPFLAGS=-Ofast -g -Wall -Wextra -DLINUX_SPI_SPIDEV -DLINUX_ARCH_RASPBERRYPI $(GATEWAY_VARS)
LDFLAGS=-lgpiod -lpthread -lrt
