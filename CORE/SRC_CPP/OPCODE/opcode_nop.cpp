#include "CORE/INCLUDE/OPCODE/opcode_nop.h"

OpCode_Nop::OpCode_Nop(Cpu &ai_cpu, Mpu &ai_mpu) : OpCode_Base(ai_cpu, ai_mpu)
{

}

void OpCode_Nop::execute(uint16_t ai_memOffset)
{
    // NOP: on ne fait rien à part incrémenter PC
    m_cpu.setRegisterPC(m_cpu.getRegisterPC() + 1u);
}

std::string OpCode_Nop::getInstruction(uint16_t ai_memOffset) const
{
    return std::string("NOP");
}
