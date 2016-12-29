#include "CORE/INCLUDE/OPCODE/opcode_jp_hl.h"

#include <sstream>

OpCode_Jp_hl::OpCode_Jp_hl(Cpu& ai_cpu, Mpu& ai_mpu) : OpCode_Base(ai_cpu, ai_mpu)
{

}

void OpCode_Jp_hl::execute(uint16_t ai_memOffset)
{
    m_cpu.setRegisterPC(m_cpu.getRegisterHL());
}

std::string OpCode_Jp_hl::getInstruction(uint16_t ai_memOffset) const
{
    std::stringstream w_sstream;
    w_sstream << "JP HL\t(HL = 0x"<< std::hex << m_cpu.getRegisterHL() << ")";
    return w_sstream.str();
}
