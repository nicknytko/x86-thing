#ifndef INTERRUPT_H
#define INTERRUPT_H

/** @brief Various values available to an irq handler.
 * Represents the stack pushed by the hardware when an IRQ is called.
 */
typedef struct s_irqStack
{
    uint32 edi, esi, ebp, esp, ebx, edx, ecx, eax; //pushed by irq handler
    /** @brief Interrupt number.  For an IRQ, this is 32 + the IRQ number. */
    uint32 nInterrupt;
    /** @brief Error code.  For an IRQ, this is always 0. */
    uint32 nError;
    uint32 eip, cs, eflags, user_esp, ss, es, ds, fs, gs; //pushed automatically by interrupt
} s_irqStack;

#define IRQ_HANDLER( name ) void name ( s_irqStack* pStack )
#define IRQ_HANDLER_NOARGS( name ) void name ()

/** Initializes the interrupt table
 */
void idt_init( );

/** Sets a bit in the IMR register
 * Used to disable a certain IRQ
 * @param nMask The number bit to set
 */
void pic_setIMRMask( uint32 nMask );

/** Clears a bit in the IMR register
 * Used to enable a certain IRQ
 * @param nMask The number bit to set
 */
void pic_clearIMRMask( uint32 nMask );

/** Sets a handler for an IRQ
 * @param pHandler Pointer to a function to be called for the IRQ
 * @param nIRQ Number of IRQ
 */
void irq_loadHandler( uint32 pHandler, uint32 nIRQ );

#endif