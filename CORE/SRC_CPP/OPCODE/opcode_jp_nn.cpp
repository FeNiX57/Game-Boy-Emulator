#include "CORE\INCLUDE\OPCODE\opcode_jp_nn.h"

#include <sstream>

OpCode_Jp_nn::OpCode_Jp_nn(Cpu& ai_cpu, Mpu& ai_mpu) : OpCode_Base(ai_cpu, ai_mpu)
{

}

void OpCode_Jp_nn::execute(uint16_t ai_memOffset)
{
    m_cpu.setRegisterPC((static_cast<uint16_t>(m_mpu.getMemVal(ai_memOffset+2)) << 8u) + static_cast<uint16_t>(m_mpu.getMemVal(ai_memOffset+1)));
}

std::string OpCode_Jp_nn::getInstruction(uint16_t ai_memOffset) const
{
    std::stringstream w_sstream;
    w_sstream << "JP nn\t(nn = 0x"<< std::hex << (static_cast<uint16_t>(m_mpu.getMemVal(ai_memOffset+2)) << 8u) + static_cast<uint16_t>(m_mpu.getMemVal(ai_memOffset+1)) << ")";
    return w_sstream.str();
}
