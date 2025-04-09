// File: "OOP1Creat3"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//��һ��ʼ��ʾ��Solve�����⣬��ʵ������û���������

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Animal//������Animal,������������������
        {
            public abstract string GetInfo();//һ�����󷽷��������ھ�������ʵ�֣��������ض�������ͺ�����
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
        //������AnimalCreator���;�����CatCreator��ApeCreator
        //������AnimalCreator������һ�����󷽷�CreateAnimal(int ind, string name)�����ݴ�������������ִ�������
        //������������ʵ����CreateAnimal��CatCreator����ind������Lion,Tiger,Leopard��ApeCreator����ind������Gorilla,Orangutan,Chimpanzee
        //AnimalCreator������һ������GetZoo(int[] inds,string[] names)���ⷽ�����ݴ������������������������ɶ�������

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

        //��������
        //1.������������inds��names���а���Ҫ�����Ķ��������������
        //2.����CatCreator��ApeCreator��ʵ�����ֱ����GetZoo�������ɶ�������cats��apes
        //3.�������ɵĶ������飬����GetInfo�������ÿ���������Ϣ
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

