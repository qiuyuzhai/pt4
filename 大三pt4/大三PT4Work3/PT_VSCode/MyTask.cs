// File: "OOP1Creat3"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Animal
        {
            public abstract string GetInfo();
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
            string name; //这个类的区域(默认是封闭的，除非你写了public在前面)
            public override string GetInfo() //一定要写override
            {
                return name; //得到区域info里的内容（null)
            }
            public Tiger(string name)
            {
                this.name = "Tiger" + name;
            }
        }
        public class Leopard : Animal
        {
            string name; //这个类的区域(默认是封闭的，除非你写了public在前面)
            public override string GetInfo() //一定要写override
            {
                return name; //得到区域info里的内容（null)
            }
            public Leopard(string name)
            {
                this.name = "Leopard" + name;
            }
        }
        public class Gorilla : Animal
        {
            string name; //这个类的区域(默认是封闭的，除非你写了public在前面)
            public override string GetInfo() //一定要写override
            {
                return name; //得到区域info里的内容（null)
            }
            public Gorilla(string name)
            {
                this.name = "Gorilla" + name;
            }
        }
        public class Orangutan : Animal
        {
            string name; //这个类的区域(默认是封闭的，除非你写了public在前面)
            public override string GetInfo() //一定要写override
            {
                return name; //得到区域info里的内容（null)
            }
            public Orangutan(string name)
            {
                this.name = "Orangutan" + name;
            }
        }
        public class Chimpanzee : Animal
        {
            string name; //这个类的区域(默认是封闭的，除非你写了public在前面)
            public override string GetInfo() //一定要写override
            {
                return name; //得到区域info里的内容（null)
            }
            public Chimpanzee(string name)
            {
                this.name = "Chimpanzee" + name;
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

            public class ApeCreator : AnimalCreator
            {
                protected override Animal CreateAnimal(int ind, string name)
                {
                    switch (ind)
                    {
                        case 0:
                            return new Gorilla(name);
                        case 1:
                            return new  Orangutan (name);
                        case 2:
                            return new Chimpanzee (name);
                        default:
                            return null;
                    }
                }
            }

            public static void Solve()
            {
                Task("OOP1Creat3");
                List<int> inds = new List<int>();
                List<string> names = new List<string>();

                for (int i = 0; i < 4; i++)
                {
                    inds.Add(GetInt());
                    names.Add(GetString());
                }

                CatCreator catCreator = new CatCreator();
                ApeCreator apeCreator = new ApeCreator();

                List<Animal> catZoo = catCreator.GetZoo(inds, names);
                List<Animal> apeZoo = apeCreator.GetZoo(inds, names);

                foreach (Animal cat in catZoo)
                {
                    Put(cat.GetInfo());
                }

                foreach (Animal ape in apeZoo)
                {
                   Put(ape.GetInfo());
                }
            }
        }
    }
}

