// File: "OOP3Behav9"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static class ReceiverA
        {
            public static void ActionA()
            {
                Put("+A");
            }
            public static void UndoActionA()
            {
                Put("-A");
            }
        }

        public static class ReceiverB
        {
            public static void ActionB()
            {
                Put("+B");
            }
            public static void UndoActionB()
            {
                Put("-B");
            }
        }

        public static class ReceiverC
        {
            public static void ActionC()
            {
                Put("+C");
            }
            public static void UndoActionC()
            {
                Put("-C");
            }
        }

        public abstract class Command
        {
            public abstract void Execute();
            public abstract void Unexecute();
        }

        // Implement the CommandA, CommandB, CommandC
        //   and MacroCommand descendant classes
        public class CommandA : Command
        {
            public override void Execute()
            {
                ReceiverA.ActionA();
            }

            public override void Unexecute()
            {
                ReceiverA.UndoActionA();
            }
        }

        public class CommandB : Command
        {
            public override void Execute()
            {
                ReceiverB.ActionB();
            }

            public override void Unexecute()
            {
                ReceiverB.UndoActionB();
            }
        }

        public class CommandC : Command
        {
            public override void Execute()
            {
                ReceiverC.ActionC();
            }

            public override void Unexecute()
            {
                ReceiverC.UndoActionC();
            }
        }

        class MacroCommand : Command
        {
            private List<Command> cmds;

            public MacroCommand(List<Command> cmds)
            {
                this.cmds = cmds;
            }

            public override void Execute()
            {
                foreach (var cmd in cmds)
                {
                    cmd.Execute();
                }
            }

            public override void Unexecute()
            {
                for (int i = cmds.Count - 1; i >= 0; i--)
                {
                    cmds[i].Unexecute();
                }
            }
        }

        public class Menu
        {
            // Add required fields
            private List<Command> menuCmds = new List<Command>();
            private List<Command> lastCmds = new List<Command>();
            private int undoIndex = -1;
            public Menu(Command cmd1, Command cmd2)
            {
                // Implement the constructor
                menuCmds.Add(cmd1);
                menuCmds.Add(cmd2);
                menuCmds.Add(new MacroCommand(new List<Command> { cmd1, cmd2 }));
            }
            public void Invoke(int cmdIndex)
            {
                // Implement the method
                if (cmdIndex >= 0 && cmdIndex < menuCmds.Count)
                {
                    var cmd = menuCmds[cmdIndex];
                    cmd.Execute();
                    lastCmds.RemoveRange(undoIndex + 1, lastCmds.Count - (undoIndex + 1));
                    lastCmds.Add(cmd);
                    undoIndex = lastCmds.Count - 1;
                }
            }
            public void Undo(int count)
            {
                // Implement the method
                while (count > 0 && undoIndex >= 0)
                {
                    lastCmds[undoIndex--].Unexecute();
                    count--;
                }
            }
            public void Redo(int count)
            {
                // Implement the method
                while (count > 0 && undoIndex < lastCmds.Count - 1)
                {
                    lastCmds[++undoIndex].Execute();
                    count--;
                }
            }
        }

        public static void Solve()
        {
            Task("OOP3Behav9");
            char C1 = GetChar();
            char C2 = GetChar();
            int N = GetInt();

            Command cmd1 = null;
            Command cmd2 = null;

            if (C1 == 'A')
            {
                cmd1 = new CommandA();
            }
            else if (C1 == 'B')
            {
                cmd1 = new CommandB();
            }
            else if (C1 == 'C')
            {
                cmd1 = new CommandC();
            }

            if (C2 == 'A')
            {
                cmd2 = new CommandA();
            }
            else if (C2 == 'B')
            {
                cmd2 = new CommandB();
            }
            else if (C2 == 'C')
            {
                cmd2 = new CommandC();
            }

            Menu M = new Menu(cmd1, cmd2);

            

            for (int i = 0; i < N; i++)
            {
                string cmd = GetString();
                char action = cmd[0];
                int value = cmd[1] - '0';

                if (action == 'I')
                {
                    M.Invoke(value);
                }
                else if (action == 'U')
                {
                    M.Undo(value);
                }
                else if (action == 'R')
                {
                    M.Redo(value);
                }
            }

        }
    }
}
