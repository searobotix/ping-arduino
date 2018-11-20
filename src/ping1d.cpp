/*
* ping1d.cpp
* A device API for the Blue Robotics Ping1D echosounder
*
*~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!
* THIS IS AN AUTOGENERATED FILE
* DO NOT EDIT
*~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!
*
*/

#include "ping1d.h"
#include "pingmessage_all.h"

Ping1D::Ping1D(Stream& ser) : _stream ( ser ) {}

Ping1D::~Ping1D()
{
    if (_profile_data) {
       free(_profile_data);
    }
}

PingMessage* Ping1D::read()
{
    while(_stream.available()) {
        if (_parser.parseByte(_stream.read()) == PingParser::NEW_MESSAGE) {
          handleMessage(&_parser.rxMsg);
          return &_parser.rxMsg;
        }
    }
    return nullptr;
}

size_t Ping1D::write(uint8_t* data, uint16_t length)
{
    return _stream.write(data, length);
}

bool Ping1D::initialize(uint16_t ping_interval_ms)
{
    if(!request(Ping1DNamespace::Device_id)) {
        return false;
    }

    if (!request(Ping1DNamespace::Firmware_version)) {
        return false;
    }

    if(!request(Ping1DNamespace::Voltage_5)) {
        return false;
    }

    if (!request(Ping1DNamespace::Processor_temperature)) {
        return false;
    }

    // Configure ping interval
    if (!set_ping_interval(ping_interval_ms)) {
        return false;
    }

    return true;
}

PingMessage* Ping1D::waitMessage(enum Ping1DNamespace::msg_ping1D_id id, uint16_t timeout_ms)
{
    uint32_t tstart = millis();
    while (millis() < tstart + timeout_ms) {

        PingMessage* pmsg = read();

        if (!pmsg) {
            continue;
        }

        handleMessage(pmsg);

        if (pmsg->message_id() == Ping1DNamespace::Nack) {
            ping_msg_ping1D_nack nack(*pmsg);

            if (nack.nacked_id() == id) {
                return nullptr;
            }
        }

        if (pmsg->message_id() == id) {
            return pmsg;
        }
    }

    return nullptr;
}

void Ping1D::handleMessage(PingMessage* pmsg)
{
    switch (pmsg->message_id()) {
        case Ping1DNamespace::Device_id:
        {
            ping_msg_ping1D_device_id m(*pmsg);
            _device_id = m.device_id();
        }
            break;

        case Ping1DNamespace::Distance:
        {
            ping_msg_ping1D_distance m(*pmsg);
            _distance = m.distance();
            _confidence = m.confidence();
            _pulse_duration = m.pulse_duration();
            _ping_number = m.ping_number();
            _scan_start = m.scan_start();
            _scan_length = m.scan_length();
            _gain_index = m.gain_index();
        }
            break;

        case Ping1DNamespace::Distance_simple:
        {
            ping_msg_ping1D_distance_simple m(*pmsg);
            _distance = m.distance();
            _confidence = m.confidence();
        }
            break;

        case Ping1DNamespace::Firmware_version:
        {
            ping_msg_ping1D_firmware_version m(*pmsg);
            _device_type = m.device_type();
            _device_model = m.device_model();
            _firmware_version_major = m.firmware_version_major();
            _firmware_version_minor = m.firmware_version_minor();
        }
            break;

        case Ping1DNamespace::Gain_index:
        {
            ping_msg_ping1D_gain_index m(*pmsg);
            _gain_index = m.gain_index();
        }
            break;

        case Ping1DNamespace::General_info:
        {
            ping_msg_ping1D_general_info m(*pmsg);
            _firmware_version_major = m.firmware_version_major();
            _firmware_version_minor = m.firmware_version_minor();
            _voltage_5 = m.voltage_5();
            _ping_interval = m.ping_interval();
            _gain_index = m.gain_index();
            _mode_auto = m.mode_auto();
        }
            break;

        case Ping1DNamespace::Mode_auto:
        {
            ping_msg_ping1D_mode_auto m(*pmsg);
            _mode_auto = m.mode_auto();
        }
            break;

        case Ping1DNamespace::Pcb_temperature:
        {
            ping_msg_ping1D_pcb_temperature m(*pmsg);
            _pcb_temperature = m.pcb_temperature();
        }
            break;

        case Ping1DNamespace::Ping_enable:
        {
            ping_msg_ping1D_ping_enable m(*pmsg);
            _ping_enabled = m.ping_enabled();
        }
            break;

        case Ping1DNamespace::Ping_interval:
        {
            ping_msg_ping1D_ping_interval m(*pmsg);
            _ping_interval = m.ping_interval();
        }
            break;

        case Ping1DNamespace::Processor_temperature:
        {
            ping_msg_ping1D_processor_temperature m(*pmsg);
            _processor_temperature = m.processor_temperature();
        }
            break;

        case Ping1DNamespace::Profile:
        {
            ping_msg_ping1D_profile m(*pmsg);
            _distance = m.distance();
            _confidence = m.confidence();
            _pulse_duration = m.pulse_duration();
            _ping_number = m.ping_number();
            _scan_start = m.scan_start();
            _scan_length = m.scan_length();
            _gain_index = m.gain_index();
            if (m.profile_data_length() > _profile_data_length) {
                if (_profile_data) {
                    free(_profile_data);
                }
                _profile_data = (uint8_t*)malloc(_profile_data_length * sizeof(uint8_t));
            }

            _profile_data_length = m.profile_data_length();

            for (uint16_t i = 0; i < _profile_data_length; i++) {
                _profile_data[i] = m.profile_data()[i];
            }
        }
            break;

        case Ping1DNamespace::Protocol_version:
        {
            ping_msg_ping1D_protocol_version m(*pmsg);
            _protocol_version = m.protocol_version();
        }
            break;

        case Ping1DNamespace::Pulse_duration:
        {
            ping_msg_ping1D_pulse_duration m(*pmsg);
            _pulse_duration = m.pulse_duration();
        }
            break;

        case Ping1DNamespace::Range:
        {
            ping_msg_ping1D_range m(*pmsg);
            _scan_start = m.scan_start();
            _scan_length = m.scan_length();
        }
            break;

        case Ping1DNamespace::Speed_of_sound:
        {
            ping_msg_ping1D_speed_of_sound m(*pmsg);
            _speed_of_sound = m.speed_of_sound();
        }
            break;

        case Ping1DNamespace::Voltage_5:
        {
            ping_msg_ping1D_voltage_5 m(*pmsg);
            _voltage_5 = m.voltage_5();
        }
            break;


        default:
            break;
    }
}

// ex ping_msg_ping1D_voltage_5 msg(*pd.request(Ping1DNamespace::Voltage_5));
PingMessage* Ping1D::request(enum Ping1DNamespace::msg_ping1D_id id, uint16_t timeout_ms)
{
    ping_msg_ping1D_empty msg;
    msg.set_id(id);
    msg.updateChecksum();
    write(msg.msgData, msg.msgDataLength());
    return waitMessage(id, timeout_ms);
}

// ex auto msg = pd.request<ping_msg_ping1D_voltage_5>();
template <typename T>
T* Ping1D::request()
{
    T resp; // todo there should be some other (static) way to get the message id?
    static ping_msg_ping1D_empty req;
    req.set_id(resp.message_id());
    req.updateChecksum();
    write(req.msgData, req.msgDataLength());
    return (T*)waitMessage(resp.message_id());
}


bool Ping1D::get_device_id(uint8_t* device_id)
{

    if (!request(Ping1DNamespace::Device_id)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (device_id) *device_id = _device_id;

    return true; // success
}

bool Ping1D::get_distance(uint32_t* distance,
                     uint16_t* confidence,
                     uint16_t* pulse_duration,
                     uint32_t* ping_number,
                     uint32_t* scan_start,
                     uint32_t* scan_length,
                     uint32_t* gain_index)
{

    if (!request(Ping1DNamespace::Distance)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (distance) *distance = _distance;
    if (confidence) *confidence = _confidence;
    if (pulse_duration) *pulse_duration = _pulse_duration;
    if (ping_number) *ping_number = _ping_number;
    if (scan_start) *scan_start = _scan_start;
    if (scan_length) *scan_length = _scan_length;
    if (gain_index) *gain_index = _gain_index;

    return true; // success
}

bool Ping1D::get_distance_simple(uint32_t* distance,
                     uint8_t* confidence)
{

    if (!request(Ping1DNamespace::Distance_simple)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (distance) *distance = _distance;
    if (confidence) *confidence = _confidence;

    return true; // success
}

bool Ping1D::get_firmware_version(uint8_t* device_type,
                     uint8_t* device_model,
                     uint16_t* firmware_version_major,
                     uint16_t* firmware_version_minor)
{

    if (!request(Ping1DNamespace::Firmware_version)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (device_type) *device_type = _device_type;
    if (device_model) *device_model = _device_model;
    if (firmware_version_major) *firmware_version_major = _firmware_version_major;
    if (firmware_version_minor) *firmware_version_minor = _firmware_version_minor;

    return true; // success
}

bool Ping1D::get_gain_index(uint32_t* gain_index)
{

    if (!request(Ping1DNamespace::Gain_index)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (gain_index) *gain_index = _gain_index;

    return true; // success
}

bool Ping1D::get_general_info(uint16_t* firmware_version_major,
                     uint16_t* firmware_version_minor,
                     uint16_t* voltage_5,
                     uint16_t* ping_interval,
                     uint8_t* gain_index,
                     uint8_t* mode_auto)
{

    if (!request(Ping1DNamespace::General_info)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (firmware_version_major) *firmware_version_major = _firmware_version_major;
    if (firmware_version_minor) *firmware_version_minor = _firmware_version_minor;
    if (voltage_5) *voltage_5 = _voltage_5;
    if (ping_interval) *ping_interval = _ping_interval;
    if (gain_index) *gain_index = _gain_index;
    if (mode_auto) *mode_auto = _mode_auto;

    return true; // success
}

bool Ping1D::get_mode_auto(uint8_t* mode_auto)
{

    if (!request(Ping1DNamespace::Mode_auto)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (mode_auto) *mode_auto = _mode_auto;

    return true; // success
}

bool Ping1D::get_pcb_temperature(uint16_t* pcb_temperature)
{

    if (!request(Ping1DNamespace::Pcb_temperature)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (pcb_temperature) *pcb_temperature = _pcb_temperature;

    return true; // success
}

bool Ping1D::get_ping_enable(uint8_t* ping_enabled)
{

    if (!request(Ping1DNamespace::Ping_enable)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (ping_enabled) *ping_enabled = _ping_enabled;

    return true; // success
}

bool Ping1D::get_ping_interval(uint16_t* ping_interval)
{

    if (!request(Ping1DNamespace::Ping_interval)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (ping_interval) *ping_interval = _ping_interval;

    return true; // success
}

bool Ping1D::get_processor_temperature(uint16_t* processor_temperature)
{

    if (!request(Ping1DNamespace::Processor_temperature)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (processor_temperature) *processor_temperature = _processor_temperature;

    return true; // success
}

bool Ping1D::get_profile(uint32_t* distance,
                     uint16_t* confidence,
                     uint16_t* pulse_duration,
                     uint32_t* ping_number,
                     uint32_t* scan_start,
                     uint32_t* scan_length,
                     uint32_t* gain_index,
                     uint16_t* profile_data_length, uint8_t** profile_data)
{

    if (!request(Ping1DNamespace::Profile)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (distance) *distance = _distance;
    if (confidence) *confidence = _confidence;
    if (pulse_duration) *pulse_duration = _pulse_duration;
    if (ping_number) *ping_number = _ping_number;
    if (scan_start) *scan_start = _scan_start;
    if (scan_length) *scan_length = _scan_length;
    if (gain_index) *gain_index = _gain_index;
    if (profile_data_length) *profile_data_length = _profile_data_length;
    if (profile_data) *profile_data = _profile_data;

    return true; // success
}

bool Ping1D::get_protocol_version(uint32_t* protocol_version)
{

    if (!request(Ping1DNamespace::Protocol_version)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (protocol_version) *protocol_version = _protocol_version;

    return true; // success
}

bool Ping1D::get_pulse_duration(uint16_t* pulse_duration)
{

    if (!request(Ping1DNamespace::Pulse_duration)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (pulse_duration) *pulse_duration = _pulse_duration;

    return true; // success
}

bool Ping1D::get_range(uint32_t* scan_start,
                     uint32_t* scan_length)
{

    if (!request(Ping1DNamespace::Range)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (scan_start) *scan_start = _scan_start;
    if (scan_length) *scan_length = _scan_length;

    return true; // success
}

bool Ping1D::get_speed_of_sound(uint32_t* speed_of_sound)
{

    if (!request(Ping1DNamespace::Speed_of_sound)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (speed_of_sound) *speed_of_sound = _speed_of_sound;

    return true; // success
}

bool Ping1D::get_voltage_5(uint16_t* voltage_5)
{

    if (!request(Ping1DNamespace::Voltage_5)) {
        return false; // no reply from device
    }

    // Copy selected fields
    if (voltage_5) *voltage_5 = _voltage_5;

    return true; // success
}


bool Ping1D::set_device_id(uint8_t device_id, bool verify)
{
    ping_msg_ping1D_set_device_id m;
    m.set_device_id(device_id);
    m.updateChecksum();
    write(m.msgData, m.msgDataLength());
    if (!request(Ping1DNamespace::Device_id)) {
        return false; // no reply from device
    }
    // Read back the data and check that changes have been applied
    if (verify
        && (_device_id != device_id)) {
        return false; // device reply does not match
    }
    return true; // success
}

bool Ping1D::set_gain_index(uint8_t gain_index, bool verify)
{
    ping_msg_ping1D_set_gain_index m;
    m.set_gain_index(gain_index);
    m.updateChecksum();
    write(m.msgData, m.msgDataLength());
    if (!request(Ping1DNamespace::Gain_index)) {
        return false; // no reply from device
    }
    // Read back the data and check that changes have been applied
    if (verify
        && (_gain_index != gain_index)) {
        return false; // device reply does not match
    }
    return true; // success
}

bool Ping1D::set_mode_auto(uint8_t mode_auto, bool verify)
{
    ping_msg_ping1D_set_mode_auto m;
    m.set_mode_auto(mode_auto);
    m.updateChecksum();
    write(m.msgData, m.msgDataLength());
    if (!request(Ping1DNamespace::Mode_auto)) {
        return false; // no reply from device
    }
    // Read back the data and check that changes have been applied
    if (verify
        && (_mode_auto != mode_auto)) {
        return false; // device reply does not match
    }
    return true; // success
}

bool Ping1D::set_ping_enable(uint8_t ping_enabled, bool verify)
{
    ping_msg_ping1D_set_ping_enable m;
    m.set_ping_enabled(ping_enabled);
    m.updateChecksum();
    write(m.msgData, m.msgDataLength());
    if (!request(Ping1DNamespace::Ping_enable)) {
        return false; // no reply from device
    }
    // Read back the data and check that changes have been applied
    if (verify
        && (_ping_enabled != ping_enabled)) {
        return false; // device reply does not match
    }
    return true; // success
}

bool Ping1D::set_ping_interval(uint16_t ping_interval, bool verify)
{
    ping_msg_ping1D_set_ping_interval m;
    m.set_ping_interval(ping_interval);
    m.updateChecksum();
    write(m.msgData, m.msgDataLength());
    if (!request(Ping1DNamespace::Ping_interval)) {
        return false; // no reply from device
    }
    // Read back the data and check that changes have been applied
    if (verify
        && (_ping_interval != ping_interval)) {
        return false; // device reply does not match
    }
    return true; // success
}

bool Ping1D::set_range(uint32_t scan_start, uint32_t scan_length, bool verify)
{
    ping_msg_ping1D_set_range m;
    m.set_scan_start(scan_start);
    m.set_scan_length(scan_length);
    m.updateChecksum();
    write(m.msgData, m.msgDataLength());
    if (!request(Ping1DNamespace::Range)) {
        return false; // no reply from device
    }
    // Read back the data and check that changes have been applied
    if (verify
        && (_scan_start != scan_start
        || _scan_length != scan_length)) {
        return false; // device reply does not match
    }
    return true; // success
}

bool Ping1D::set_speed_of_sound(uint32_t speed_of_sound, bool verify)
{
    ping_msg_ping1D_set_speed_of_sound m;
    m.set_speed_of_sound(speed_of_sound);
    m.updateChecksum();
    write(m.msgData, m.msgDataLength());
    if (!request(Ping1DNamespace::Speed_of_sound)) {
        return false; // no reply from device
    }
    // Read back the data and check that changes have been applied
    if (verify
        && (_speed_of_sound != speed_of_sound)) {
        return false; // device reply does not match
    }
    return true; // success
}

