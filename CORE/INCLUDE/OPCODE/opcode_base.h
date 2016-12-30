#ifndef OPCODE_BASE_H
#define OPCODE_BASE_H

#include "opcode_intf.h"


class OpCode_Base : public OpCode_Intf
{
public:
    OpCode_Base(Cpu& ai_cpu, Mpu& ai_mpu);

protected:
    uint8_t _decodeAndGetRegister8Bits(uint8_t ai_register) const;
    void _decodeAndSetRegister8Bits(uint8_t ai_register, uint8_t ai_value);
    std::string _decodeAndGetNameRegister8Bits(uint8_t ai_register) const;

    uint16_t _decodeAndGetRegister16Bits(uint16_t ai_memOffset) const;
    void _decodeAndSetRegister16Bits(uint16_t ai_memOffset, uint16_t ai_value);
    std::string _decodeAndGetNameRegister16Bits(uint16_t ai_memOffset) const;

    bool _decodeAndTestCondition(uint16_t ai_memOffset) const;
    std::string _decodeAndGetNameCondition(uint16_t ai_memOffset) const;

    inline uint16_t _get16BitData(uint16_t ai_memOffset) const {
        return (static_cast<uint16_t>(m_mpu.getMemVal(ai_memOffset+2)) << 8u) + static_cast<uint16_t>(m_mpu.getMemVal(ai_memOffset+1));
    }

protected:
    Cpu& m_cpu;
    Mpu& m_mpu;
};

#endif // OPCODE_BASE_H
