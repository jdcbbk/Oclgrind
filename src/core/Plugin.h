// Plugin.h (Oclgrind)
// Copyright (c) 2013-2014, James Price and Simon McIntosh-Smith,
// University of Bristol. All rights reserved.
//
// This program is provided under a three-clause BSD license. For full
// license terms please see the LICENSE file distributed with this
// source code.

#pragma once

#include "common.h"

namespace oclgrind
{
  class Context;
  class Kernel;
  class KernelInvocation;
  class Memory;
  class WorkGroup;
  class WorkItem;

  class Plugin
  {
  public:
    Plugin(const Context *context);

    virtual void instructionExecuted(const WorkItem *workItem,
                                     const llvm::Instruction *instruction,
                                     const TypedValue& result){}
    virtual void kernelBegin(KernelInvocation *kernelInvocation){}
    virtual void kernelEnd(KernelInvocation *kernelInvocation){}
    virtual void memoryAllocated(const Memory *memory, size_t address,
                                 size_t size){}
    virtual void memoryAtomic(const Memory *memory, size_t address,
                              size_t size){}
    virtual void memoryDeallocated(const Memory *memory, size_t address){}
    virtual void memoryLoad(const Memory *memory, size_t address, size_t size){}
    virtual void memoryStore(const Memory *memory, size_t address, size_t size,
                             const uint8_t *storeData){}
    virtual void workGroupBarrier(const WorkGroup *workGroup, uint32_t flags){}

  protected:
    const Context *m_context;
  };
}