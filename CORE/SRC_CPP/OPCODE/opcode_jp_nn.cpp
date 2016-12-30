#include "CORE\INCLUDE\OPCODE\opcode_jp_nn.h"

#include <sstream>

OpCode_Jp_nn::OpCode_Jp_nn(Cpu& ai_cpu, Mpu& ai_mpu) : OpCode_Base(ai_cpu, ai_mpu)
{

}

void OpCode_Jp_nn::execute(uint16_t ai_memOffset)
{
    m_cpu.setRegisterPC(_get16BitData(ai_memOffset));
}

std::string OpCode_Jp_nn::getInstruction(uint16_t ai_memOffset) const
{
    std::stringstream w_sstream;
    w_sstream << "JP nn\t(nn = 0x"<< std::hex << _get16BitData(ai_memOffset) << ")";
    return w_sstream.str();
}
