#include "CORE/INCLUDE/OPCODE/opcode_ld_a_r.h"

#include <sstream>

OpCode_Ld_a_r::OpCode_Ld_a_r(Cpu& ai_cpu, Mpu& ai_mpu) : OpCode_Base(ai_cpu, ai_mpu)
{

}

void OpCode_Ld_a_r::execute(uint16_t ai_memOffset)
{
    uint16_t w_adress = _decodeAndGetRegister16Bits(ai_memOffset);
    m_cpu.setRegisterA(m_mpu.getMemVal(w_adress));

    m_cpu.setRegisterPC(m_cpu.getRegisterPC() + 1u);
}

std::string OpCode_Ld_a_r::getInstruction(uint16_t ai_memOffset) const
{
    std::stringstream w_sstream;
    w_sstream << "LD A, (R)\t(R = " << _decodeAndGetNameRegister16Bits(ai_memOffset)
              << ", (R) = 0x" << std::hex << _decodeAndGetRegister16Bits(ai_memOffset)
              << ")";
    return w_sstream.str();
}
