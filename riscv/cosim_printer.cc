#include <sys/time.h>
#include "devices.h"
#include "processor.h"
#include "term.h"

cosim_printer_t::cosim_printer_t()
{
  /* register_value is the value of the register at U0_SIM_APB__SAIF_BD_APB__BASE_ADDR */
  register_value = 0;
}


bool cosim_printer_t::load(reg_t addr, size_t len, uint8_t* bytes)
{
  bytes[0] = register_value;
  return true;
}

bool cosim_printer_t::store(reg_t addr, size_t len, const uint8_t* bytes)
{
  register_value = bytes[0];
  canonical_terminal_t::write(bytes[0]);
  return true;
}

