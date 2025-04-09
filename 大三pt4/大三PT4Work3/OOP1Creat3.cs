// File: "OOP1Creat3"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//它一开始显示是Solve的问题，其实是括号没对齐的问题

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Animal//抽象类Animal,具体类有下面那六个
        {
            public abstract string GetInfo();//一个抽象方法，用来在具体类中实现，用来返回动物的类型和名字
        }

        public class Lion : Animal
        {
            string name;
            public Lion(string name)
            {
                this.name = name;
            }
            public override string GetInfo()
            {
                return "Lion " + name;
            }
        }

        // Implement the Tiger, Leopard, Gorilla,
        //   Orangutan and Chimpanzee descendant classes
        public class Tiger : Animal
        {
            string name;
            public Tiger(string name)
            {
                this.name = name;
            }
            public override string GetInfo()
            {
                return "Tiger " + name;
            }

        }
        public class Leopard : Animal
        {
            string name;

            public Leopard(string name)
            {
                this.name = name;
            }
            public override string GetInfo()
            {
                return "Leopard " + name;
            }

        }
        public class Gorilla : Animal
        {
            string name;
            public Gorilla(string name)
            {
                this.name = name;
            }
            public override string GetInfo()
            {
                return "Gorilla " + name;
            }

        }
        public class Orangutan : Animal
        {
            string name;
            public Orangutan(string name)
            {
                this.name = name;
            }
            public override string GetInfo()
            {
                return "Orangutan " + name;
            }

        }
        public class Chimpanzee : Animal
        {
            string name;
            public Chimpanzee(string name)
            {
                this.name = name;
            }
            public override string GetInfo()
            {
                return "Chimpanzee " + name;
            }

        }


        public abstract class AnimalCreator
        {
            protected abstract Animal CreateAnimal(int ind, string name);
            public Animal[] GetZoo(int[] inds, string[] names)
            {
                Animal[] zoo = new Animal[inds.Length];
                for (int i = 0; i < zoo.Length; i++)
                    zoo[i] = CreateAnimal(inds[i], names[i]);
                return zoo;
            }
        }

        // Implement the CatCreator and ApeCreator descendant classes
        //抽象类AnimalCreator，和具体类CatCreator和ApeCreator
        //抽象类AnimalCreator定义了一个抽象方法CreateAnimal(int ind, string name)来根据传入的索引和名字创建动物
        //那两个具体类实现了CreateAnimal，CatCreator根据ind来创建Lion,Tiger,Leopard，ApeCreator根据ind来创建Gorilla,Orangutan,Chimpanzee
        //AnimalCreator定义了一个方法GetZoo(int[] inds,string[] names)，这方法根据传入的索引数组和名字数组生成动物数组

        public class CatCreator : AnimalCreator
        {
            protected override Animal CreateAnimal(int ind, string name)
            {
                switch (ind)
                {
                    case 0:
                        return new Lion(name);
                    case 1:
                        return new Tiger(name);
                    case 2:
                        return new Leopard(name);
                    default:
                        return null;
                }
            }
        }

        public class ApeCreator : AnimalCreator
        {
            protected override Animal CreateAnimal(int ind, string name)
            {
                switch (ind)
                {
                    case 0:
                        return new Gorilla(name);
                    case 1:
                        return new Orangutan(name);
                    case 2:
                        return new Chimpanzee(name);
                    default:
                        return null;
                }
            }
        }

        //主方法：
        //1.创建两个数组inds和names其中包含要创建的动物的索引和名字
        //2.创建CatCreator和ApeCreator的实例，分别调用GetZoo方法生成动物数组cats和apes
        //3.遍历生成的动物数组，调用GetInfo方法输出每个动物的信息
        public static void Solve()
        {
            Task("OOP1Creat3");
            int[] inds = new int[4];
            string[] names = new string[4];
            for (int i = 0; i < 4; i++)
            {
                inds[i] = GetInt();
                names[i] = GetString();
            }

            CatCreator catCreator = new CatCreator();
            ApeCreator apeCreator = new ApeCreator();

            Animal[] cats = catCreator.GetZoo(inds, names);
            Animal[] apes = apeCreator.GetZoo(inds, names);

            foreach (Animal cat in cats)
            {
                Put(cat.GetInfo());
            }

            foreach (Animal ape in apes)
            {
                Put(ape.GetInfo());
            }
        }

    }
}

