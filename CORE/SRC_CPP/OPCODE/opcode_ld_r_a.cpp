#include "CORE/INCLUDE/OPCODE/opcode_ld_r_a.h"

#include <sstream>

OpCode_Ld_r_a::OpCode_Ld_r_a(Cpu& ai_cpu, Mpu& ai_mpu) : OpCode_Base(ai_cpu, ai_mpu)
{

}

void OpCode_Ld_r_a::execute(uint16_t ai_memOffset)
{
    uint16_t w_adress = _decodeAndGetRegister16Bits(ai_memOffset);
    m_mpu.setMemVal(w_adress, m_cpu.getRegisterA());

    m_cpu.setRegisterPC(m_cpu.getRegisterPC() + 1u);
}

std::string OpCode_Ld_r_a::getInstruction(uint16_t ai_memOffset) const
{
    std::stringstream w_sstream;
    w_sstream << "LD (R), A\t(R = " << _decodeAndGetNameRegister16Bits(ai_memOffset)
              << ", (R) = 0x" << std::hex << _decodeAndGetRegister16Bits(ai_memOffset)
              << ", A = " << m_cpu.getRegisterA() << ")";
    return w_sstream.str();
}
