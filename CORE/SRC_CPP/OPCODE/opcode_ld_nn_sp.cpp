#include "CORE/INCLUDE/OPCODE/opcode_ld_nn_sp.h"

#include <sstream>

OpCode_Ld_nn_sp::OpCode_Ld_nn_sp(Cpu& ai_cpu, Mpu& ai_mpu) : OpCode_Base(ai_cpu, ai_mpu)
{

}

void OpCode_Ld_nn_sp::execute(uint16_t ai_memOffset)
{
    uint16_t w_address = _get16BitData(ai_memOffset);

    // Mise en place du LSB en premier dans la mémoire
    m_mpu.setMemVal(w_address, static_cast<uint8_t>(m_cpu.getRegisterSP()&0x00FFu));

    // Mise en place du MSB en deuxième dans la mémoire
    m_mpu.setMemVal(w_address + 1, static_cast<uint8_t>((m_cpu.getRegisterSP()&0xFF00u)>>8u));

    m_cpu.setRegisterPC(m_cpu.getRegisterPC()+3u);
}

std::string OpCode_Ld_nn_sp::getInstruction(uint16_t ai_memOffset) const
{
    std::stringstream w_sstream;
    w_sstream << "LD (NN), SP\t(NN = 0x" << std::hex << _get16BitData(ai_memOffset) << ")";
    return w_sstream.str();
}
