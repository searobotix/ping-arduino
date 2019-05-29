// C++ implementation of the Blue Robotics 'Ping' binary message protocol

//~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!
// THIS IS AN AUTOGENERATED FILE
// DO NOT EDIT
//~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!

#pragma once

#ifdef QT_CORE_LIB
#include <QObject>
#endif

#include "ping_message.h"

/// ping_ping1D objects provide a wrapper over vector
/// for convenient access and packing of field data
///
/// These files are generated by the ping_generator.py
/// script found in this directory

namespace PingPing1DNamespace {
#ifdef QT_CORE_LIB
    Q_NAMESPACE
#endif
    enum ping_ping1D_id {
        SetDeviceId = 1000,
        SetRange = 1001,
        SetSpeedOfSound = 1002,
        SetModeAuto = 1003,
        SetPingInterval = 1004,
        SetGainSetting = 1005,
        SetPingEnable = 1006,
        FirmwareVersion = 1200,
        DeviceId = 1201,
        Voltage5 = 1202,
        SpeedOfSound = 1203,
        Range = 1204,
        ModeAuto = 1205,
        PingInterval = 1206,
        GainSetting = 1207,
        TransmitDuration = 1208,
        GeneralInfo = 1210,
        DistanceSimple = 1211,
        Distance = 1212,
        ProcessorTemperature = 1213,
        PcbTemperature = 1214,
        PingEnable = 1215,
        Profile = 1300,
        GotoBootloader = 1100,
        ContinuousStart = 1400,
        ContinuousStop = 1401,
    };
#ifdef QT_CORE_LIB
    Q_ENUM_NS(ping_ping1D_id)
#endif
};

class ping_ping1D_set_device_id : public ping_message
{
public:
    ping_ping1D_set_device_id(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_set_device_id(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_set_device_id()
        : ping_message { static_cast<uint16_t>(11) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 1; // payload size
        (uint16_t&)msgData[4] = 1000; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint8_t device_id() const { uint8_t d; memcpy(&d, (payload_data(0)), 1.0); return d; };
    void set_device_id(const uint8_t device_id) { memcpy((payload_data(0)), &device_id, 1.0);};
};

class ping_ping1D_set_range : public ping_message
{
public:
    ping_ping1D_set_range(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_set_range(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_set_range()
        : ping_message { static_cast<uint16_t>(18) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 8; // payload size
        (uint16_t&)msgData[4] = 1001; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint32_t scan_start() const { uint32_t d; memcpy(&d, (payload_data(0)), 4.0); return d; };
    void set_scan_start(const uint32_t scan_start) { memcpy((payload_data(0)), &scan_start, 4.0);};
    uint32_t scan_length() const { uint32_t d; memcpy(&d, (payload_data(4.0)), 4.0); return d; };
    void set_scan_length(const uint32_t scan_length) { memcpy((payload_data(4.0)), &scan_length, 4.0);};
};

class ping_ping1D_set_speed_of_sound : public ping_message
{
public:
    ping_ping1D_set_speed_of_sound(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_set_speed_of_sound(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_set_speed_of_sound()
        : ping_message { static_cast<uint16_t>(14) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 4; // payload size
        (uint16_t&)msgData[4] = 1002; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint32_t speed_of_sound() const { uint32_t d; memcpy(&d, (payload_data(0)), 4.0); return d; };
    void set_speed_of_sound(const uint32_t speed_of_sound) { memcpy((payload_data(0)), &speed_of_sound, 4.0);};
};

class ping_ping1D_set_mode_auto : public ping_message
{
public:
    ping_ping1D_set_mode_auto(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_set_mode_auto(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_set_mode_auto()
        : ping_message { static_cast<uint16_t>(11) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 1; // payload size
        (uint16_t&)msgData[4] = 1003; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint8_t mode_auto() const { uint8_t d; memcpy(&d, (payload_data(0)), 1.0); return d; };
    void set_mode_auto(const uint8_t mode_auto) { memcpy((payload_data(0)), &mode_auto, 1.0);};
};

class ping_ping1D_set_ping_interval : public ping_message
{
public:
    ping_ping1D_set_ping_interval(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_set_ping_interval(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_set_ping_interval()
        : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 2; // payload size
        (uint16_t&)msgData[4] = 1004; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t ping_interval() const { uint16_t d; memcpy(&d, (payload_data(0)), 2.0); return d; };
    void set_ping_interval(const uint16_t ping_interval) { memcpy((payload_data(0)), &ping_interval, 2.0);};
};

class ping_ping1D_set_gain_setting : public ping_message
{
public:
    ping_ping1D_set_gain_setting(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_set_gain_setting(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_set_gain_setting()
        : ping_message { static_cast<uint16_t>(11) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 1; // payload size
        (uint16_t&)msgData[4] = 1005; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint8_t gain_setting() const { uint8_t d; memcpy(&d, (payload_data(0)), 1.0); return d; };
    void set_gain_setting(const uint8_t gain_setting) { memcpy((payload_data(0)), &gain_setting, 1.0);};
};

class ping_ping1D_set_ping_enable : public ping_message
{
public:
    ping_ping1D_set_ping_enable(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_set_ping_enable(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_set_ping_enable()
        : ping_message { static_cast<uint16_t>(11) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 1; // payload size
        (uint16_t&)msgData[4] = 1006; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint8_t ping_enabled() const { uint8_t d; memcpy(&d, (payload_data(0)), 1.0); return d; };
    void set_ping_enabled(const uint8_t ping_enabled) { memcpy((payload_data(0)), &ping_enabled, 1.0);};
};

class ping_ping1D_firmware_version : public ping_message
{
public:
    ping_ping1D_firmware_version(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_firmware_version(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_firmware_version()
        : ping_message { static_cast<uint16_t>(16) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 6; // payload size
        (uint16_t&)msgData[4] = 1200; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint8_t device_type() const { uint8_t d; memcpy(&d, (payload_data(0)), 1.0); return d; };
    void set_device_type(const uint8_t device_type) { memcpy((payload_data(0)), &device_type, 1.0);};
    uint8_t device_model() const { uint8_t d; memcpy(&d, (payload_data(1.0)), 1.0); return d; };
    void set_device_model(const uint8_t device_model) { memcpy((payload_data(1.0)), &device_model, 1.0);};
    uint16_t firmware_version_major() const { uint16_t d; memcpy(&d, (payload_data(2.0)), 2.0); return d; };
    void set_firmware_version_major(const uint16_t firmware_version_major) { memcpy((payload_data(2.0)), &firmware_version_major, 2.0);};
    uint16_t firmware_version_minor() const { uint16_t d; memcpy(&d, (payload_data(4.0)), 2.0); return d; };
    void set_firmware_version_minor(const uint16_t firmware_version_minor) { memcpy((payload_data(4.0)), &firmware_version_minor, 2.0);};
};

class ping_ping1D_device_id : public ping_message
{
public:
    ping_ping1D_device_id(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_device_id(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_device_id()
        : ping_message { static_cast<uint16_t>(11) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 1; // payload size
        (uint16_t&)msgData[4] = 1201; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint8_t device_id() const { uint8_t d; memcpy(&d, (payload_data(0)), 1.0); return d; };
    void set_device_id(const uint8_t device_id) { memcpy((payload_data(0)), &device_id, 1.0);};
};

class ping_ping1D_voltage_5 : public ping_message
{
public:
    ping_ping1D_voltage_5(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_voltage_5(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_voltage_5()
        : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 2; // payload size
        (uint16_t&)msgData[4] = 1202; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t voltage_5() const { uint16_t d; memcpy(&d, (payload_data(0)), 2.0); return d; };
    void set_voltage_5(const uint16_t voltage_5) { memcpy((payload_data(0)), &voltage_5, 2.0);};
};

class ping_ping1D_speed_of_sound : public ping_message
{
public:
    ping_ping1D_speed_of_sound(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_speed_of_sound(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_speed_of_sound()
        : ping_message { static_cast<uint16_t>(14) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 4; // payload size
        (uint16_t&)msgData[4] = 1203; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint32_t speed_of_sound() const { uint32_t d; memcpy(&d, (payload_data(0)), 4.0); return d; };
    void set_speed_of_sound(const uint32_t speed_of_sound) { memcpy((payload_data(0)), &speed_of_sound, 4.0);};
};

class ping_ping1D_range : public ping_message
{
public:
    ping_ping1D_range(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_range(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_range()
        : ping_message { static_cast<uint16_t>(18) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 8; // payload size
        (uint16_t&)msgData[4] = 1204; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint32_t scan_start() const { uint32_t d; memcpy(&d, (payload_data(0)), 4.0); return d; };
    void set_scan_start(const uint32_t scan_start) { memcpy((payload_data(0)), &scan_start, 4.0);};
    uint32_t scan_length() const { uint32_t d; memcpy(&d, (payload_data(4.0)), 4.0); return d; };
    void set_scan_length(const uint32_t scan_length) { memcpy((payload_data(4.0)), &scan_length, 4.0);};
};

class ping_ping1D_mode_auto : public ping_message
{
public:
    ping_ping1D_mode_auto(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_mode_auto(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_mode_auto()
        : ping_message { static_cast<uint16_t>(11) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 1; // payload size
        (uint16_t&)msgData[4] = 1205; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint8_t mode_auto() const { uint8_t d; memcpy(&d, (payload_data(0)), 1.0); return d; };
    void set_mode_auto(const uint8_t mode_auto) { memcpy((payload_data(0)), &mode_auto, 1.0);};
};

class ping_ping1D_ping_interval : public ping_message
{
public:
    ping_ping1D_ping_interval(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_ping_interval(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_ping_interval()
        : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 2; // payload size
        (uint16_t&)msgData[4] = 1206; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t ping_interval() const { uint16_t d; memcpy(&d, (payload_data(0)), 2.0); return d; };
    void set_ping_interval(const uint16_t ping_interval) { memcpy((payload_data(0)), &ping_interval, 2.0);};
};

class ping_ping1D_gain_setting : public ping_message
{
public:
    ping_ping1D_gain_setting(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_gain_setting(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_gain_setting()
        : ping_message { static_cast<uint16_t>(14) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 4; // payload size
        (uint16_t&)msgData[4] = 1207; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint32_t gain_setting() const { uint32_t d; memcpy(&d, (payload_data(0)), 4.0); return d; };
    void set_gain_setting(const uint32_t gain_setting) { memcpy((payload_data(0)), &gain_setting, 4.0);};
};

class ping_ping1D_transmit_duration : public ping_message
{
public:
    ping_ping1D_transmit_duration(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_transmit_duration(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_transmit_duration()
        : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 2; // payload size
        (uint16_t&)msgData[4] = 1208; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t transmit_duration() const { uint16_t d; memcpy(&d, (payload_data(0)), 2.0); return d; };
    void set_transmit_duration(const uint16_t transmit_duration) { memcpy((payload_data(0)), &transmit_duration, 2.0);};
};

class ping_ping1D_general_info : public ping_message
{
public:
    ping_ping1D_general_info(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_general_info(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_general_info()
        : ping_message { static_cast<uint16_t>(20) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 10; // payload size
        (uint16_t&)msgData[4] = 1210; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t firmware_version_major() const { uint16_t d; memcpy(&d, (payload_data(0)), 2.0); return d; };
    void set_firmware_version_major(const uint16_t firmware_version_major) { memcpy((payload_data(0)), &firmware_version_major, 2.0);};
    uint16_t firmware_version_minor() const { uint16_t d; memcpy(&d, (payload_data(2.0)), 2.0); return d; };
    void set_firmware_version_minor(const uint16_t firmware_version_minor) { memcpy((payload_data(2.0)), &firmware_version_minor, 2.0);};
    uint16_t voltage_5() const { uint16_t d; memcpy(&d, (payload_data(4.0)), 2.0); return d; };
    void set_voltage_5(const uint16_t voltage_5) { memcpy((payload_data(4.0)), &voltage_5, 2.0);};
    uint16_t ping_interval() const { uint16_t d; memcpy(&d, (payload_data(6.0)), 2.0); return d; };
    void set_ping_interval(const uint16_t ping_interval) { memcpy((payload_data(6.0)), &ping_interval, 2.0);};
    uint8_t gain_setting() const { uint8_t d; memcpy(&d, (payload_data(8.0)), 1.0); return d; };
    void set_gain_setting(const uint8_t gain_setting) { memcpy((payload_data(8.0)), &gain_setting, 1.0);};
    uint8_t mode_auto() const { uint8_t d; memcpy(&d, (payload_data(9.0)), 1.0); return d; };
    void set_mode_auto(const uint8_t mode_auto) { memcpy((payload_data(9.0)), &mode_auto, 1.0);};
};

class ping_ping1D_distance_simple : public ping_message
{
public:
    ping_ping1D_distance_simple(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_distance_simple(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_distance_simple()
        : ping_message { static_cast<uint16_t>(15) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 5; // payload size
        (uint16_t&)msgData[4] = 1211; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint32_t distance() const { uint32_t d; memcpy(&d, (payload_data(0)), 4.0); return d; };
    void set_distance(const uint32_t distance) { memcpy((payload_data(0)), &distance, 4.0);};
    uint8_t confidence() const { uint8_t d; memcpy(&d, (payload_data(4.0)), 1.0); return d; };
    void set_confidence(const uint8_t confidence) { memcpy((payload_data(4.0)), &confidence, 1.0);};
};

class ping_ping1D_distance : public ping_message
{
public:
    ping_ping1D_distance(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_distance(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_distance()
        : ping_message { static_cast<uint16_t>(34) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 24; // payload size
        (uint16_t&)msgData[4] = 1212; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint32_t distance() const { uint32_t d; memcpy(&d, (payload_data(0)), 4.0); return d; };
    void set_distance(const uint32_t distance) { memcpy((payload_data(0)), &distance, 4.0);};
    uint16_t confidence() const { uint16_t d; memcpy(&d, (payload_data(4.0)), 2.0); return d; };
    void set_confidence(const uint16_t confidence) { memcpy((payload_data(4.0)), &confidence, 2.0);};
    uint16_t transmit_duration() const { uint16_t d; memcpy(&d, (payload_data(6.0)), 2.0); return d; };
    void set_transmit_duration(const uint16_t transmit_duration) { memcpy((payload_data(6.0)), &transmit_duration, 2.0);};
    uint32_t ping_number() const { uint32_t d; memcpy(&d, (payload_data(8.0)), 4.0); return d; };
    void set_ping_number(const uint32_t ping_number) { memcpy((payload_data(8.0)), &ping_number, 4.0);};
    uint32_t scan_start() const { uint32_t d; memcpy(&d, (payload_data(12.0)), 4.0); return d; };
    void set_scan_start(const uint32_t scan_start) { memcpy((payload_data(12.0)), &scan_start, 4.0);};
    uint32_t scan_length() const { uint32_t d; memcpy(&d, (payload_data(16.0)), 4.0); return d; };
    void set_scan_length(const uint32_t scan_length) { memcpy((payload_data(16.0)), &scan_length, 4.0);};
    uint32_t gain_setting() const { uint32_t d; memcpy(&d, (payload_data(20.0)), 4.0); return d; };
    void set_gain_setting(const uint32_t gain_setting) { memcpy((payload_data(20.0)), &gain_setting, 4.0);};
};

class ping_ping1D_processor_temperature : public ping_message
{
public:
    ping_ping1D_processor_temperature(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_processor_temperature(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_processor_temperature()
        : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 2; // payload size
        (uint16_t&)msgData[4] = 1213; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t processor_temperature() const { uint16_t d; memcpy(&d, (payload_data(0)), 2.0); return d; };
    void set_processor_temperature(const uint16_t processor_temperature) { memcpy((payload_data(0)), &processor_temperature, 2.0);};
};

class ping_ping1D_pcb_temperature : public ping_message
{
public:
    ping_ping1D_pcb_temperature(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_pcb_temperature(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_pcb_temperature()
        : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 2; // payload size
        (uint16_t&)msgData[4] = 1214; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t pcb_temperature() const { uint16_t d; memcpy(&d, (payload_data(0)), 2.0); return d; };
    void set_pcb_temperature(const uint16_t pcb_temperature) { memcpy((payload_data(0)), &pcb_temperature, 2.0);};
};

class ping_ping1D_ping_enable : public ping_message
{
public:
    ping_ping1D_ping_enable(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_ping_enable(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_ping_enable()
        : ping_message { static_cast<uint16_t>(11) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 1; // payload size
        (uint16_t&)msgData[4] = 1215; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint8_t ping_enabled() const { uint8_t d; memcpy(&d, (payload_data(0)), 1.0); return d; };
    void set_ping_enabled(const uint8_t ping_enabled) { memcpy((payload_data(0)), &ping_enabled, 1.0);};
};

class ping_ping1D_profile : public ping_message
{
public:
    ping_ping1D_profile(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_profile(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_profile(uint16_t profile_data_length
)
        : ping_message { static_cast<uint16_t>(36 + profile_data_length) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 26 + profile_data_length; // payload size
        (uint16_t&)msgData[4] = 1300; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint32_t distance() const { uint32_t d; memcpy(&d, (payload_data(0)), 4.0); return d; };
    void set_distance(const uint32_t distance) { memcpy((payload_data(0)), &distance, 4.0);};
    uint16_t confidence() const { uint16_t d; memcpy(&d, (payload_data(4.0)), 2.0); return d; };
    void set_confidence(const uint16_t confidence) { memcpy((payload_data(4.0)), &confidence, 2.0);};
    uint16_t transmit_duration() const { uint16_t d; memcpy(&d, (payload_data(6.0)), 2.0); return d; };
    void set_transmit_duration(const uint16_t transmit_duration) { memcpy((payload_data(6.0)), &transmit_duration, 2.0);};
    uint32_t ping_number() const { uint32_t d; memcpy(&d, (payload_data(8.0)), 4.0); return d; };
    void set_ping_number(const uint32_t ping_number) { memcpy((payload_data(8.0)), &ping_number, 4.0);};
    uint32_t scan_start() const { uint32_t d; memcpy(&d, (payload_data(12.0)), 4.0); return d; };
    void set_scan_start(const uint32_t scan_start) { memcpy((payload_data(12.0)), &scan_start, 4.0);};
    uint32_t scan_length() const { uint32_t d; memcpy(&d, (payload_data(16.0)), 4.0); return d; };
    void set_scan_length(const uint32_t scan_length) { memcpy((payload_data(16.0)), &scan_length, 4.0);};
    uint32_t gain_setting() const { uint32_t d; memcpy(&d, (payload_data(20.0)), 4.0); return d; };
    void set_gain_setting(const uint32_t gain_setting) { memcpy((payload_data(20.0)), &gain_setting, 4.0);};
    uint16_t profile_data_length() const { uint16_t d; memcpy(&d, (payload_data(24.0)), 2.0); return d; };
    //TODO do this in constructor (const)
    void set_profile_data_length(const uint16_t profile_data_length) { memcpy((payload_data(24.0)), &profile_data_length, 2.0);};
    uint8_t* profile_data() const { return (uint8_t*)(payload_data(26.0)); }
    void set_profile_data_at(const uint16_t i, const uint8_t data) { memcpy((payload_data(26.0 + i)), &data, 1); }
};

class ping_ping1D_goto_bootloader : public ping_message
{
public:
    ping_ping1D_goto_bootloader(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_goto_bootloader(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_goto_bootloader()
        : ping_message { static_cast<uint16_t>(10) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 0; // payload size
        (uint16_t&)msgData[4] = 1100; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

};

class ping_ping1D_continuous_start : public ping_message
{
public:
    ping_ping1D_continuous_start(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_continuous_start(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_continuous_start()
        : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 2; // payload size
        (uint16_t&)msgData[4] = 1400; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t id() const { uint16_t d; memcpy(&d, (payload_data(0)), 2.0); return d; };
    void set_id(const uint16_t id) { memcpy((payload_data(0)), &id, 2.0);};
};

class ping_ping1D_continuous_stop : public ping_message
{
public:
    ping_ping1D_continuous_stop(const ping_message& msg) : ping_message { msg } {}
    ping_ping1D_continuous_stop(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    ping_ping1D_continuous_stop()
        : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = 2; // payload size
        (uint16_t&)msgData[4] = 1401; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t id() const { uint16_t d; memcpy(&d, (payload_data(0)), 2.0); return d; };
    void set_id(const uint16_t id) { memcpy((payload_data(0)), &id, 2.0);};
};

