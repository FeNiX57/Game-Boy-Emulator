#include "CORE/INCLUDE/OPCODE/opcode_jr_cc_n.h"

#include <sstream>

OpCode_Jr_cc_n::OpCode_Jr_cc_n(Cpu &ai_cpu, Mpu &ai_mpu) : OpCode_Base(ai_cpu, ai_mpu)
{

}

void OpCode_Jr_cc_n::execute(uint16_t ai_memOffset)
{
    if (_decodeAndTestCondition(ai_memOffset)) {
        uint8_t w_n = m_mpu.getMemVal(ai_memOffset+1u);
        m_cpu.setRegisterPC(m_cpu.getRegisterPC() + static_cast<uint16_t>(w_n));
    }
    else {
        m_cpu.setRegisterPC(m_cpu.getRegisterPC() + 2u);
    }
}

std::string OpCode_Jr_cc_n::getInstruction(uint16_t ai_memOffset) const
{
    std::stringstream w_sstream;
    w_sstream << "JR CC, N\t(CC = " << _decodeAndGetNameCondition(ai_memOffset);
    w_sstream << ", N = " << std::hex << "0x" << m_mpu.getMemVal(ai_memOffset+1u) << ")\t";
    if (_decodeAndTestCondition(ai_memOffset)) {
        w_sstream << "(VALID)";
    }
    else {
        w_sstream << "(NOT VALID)";
    }
    return w_sstream.str();
}
