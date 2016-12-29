#include "CORE/INCLUDE/OPCODE/opcode_jr_n.h"

#include <sstream>

OpCode_Jr_n::OpCode_Jr_n(Cpu& ai_cpu, Mpu& ai_mpu) : OpCode_Base(ai_cpu, ai_mpu)
{

}

void OpCode_Jr_n::execute(uint16_t ai_memOffset)
{
    uint8_t w_n = m_mpu.getMemVal(ai_memOffset+1u);

    m_cpu.setRegisterPC(m_cpu.getRegisterPC() + static_cast<uint16_t>(w_n));
}

std::string OpCode_Jr_n::getInstruction(uint16_t ai_memOffset) const
{
    std::stringstream w_sstream;
    w_sstream << "JR n\t(n = ";
    w_sstream << m_mpu.getMemVal(ai_memOffset+1u);
    w_sstream << ")";
    return w_sstream.str();
}
